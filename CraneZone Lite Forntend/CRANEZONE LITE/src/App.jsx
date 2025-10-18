import { useState, useEffect } from 'react';
import { Activity, AlertTriangle, Users, Package } from 'lucide-react';
import socketService from './services/socketService';
import VideoFeed from './components/VideoFeed';
import AlertList from './components/AlertList';
import StatsCard from './components/StatsCard';
import ConnectionStatus from './components/ConnectionStatus';
import DetectionChart from './components/DetectionChart';
import './App.css';

function App() {
  const [isConnected, setIsConnected] = useState(false);
  const [alerts, setAlerts] = useState([]);
  const [detections, setDetections] = useState([]);
  const [stats, setStats] = useState({
    totalDetections: 0,
    activeAlerts: 0,
    personsDetected: 0,
    objectsDetected: 0,
  });
  const [chartData, setChartData] = useState([]);

  useEffect(() => {
    socketService.connect();

    const handleConnect = () => {
      console.log('Connected to backend');
      setIsConnected(true);
    };

    const handleDisconnect = () => {
      console.log('Disconnected from backend');
      setIsConnected(false);
    };

    const handleDetection = (data) => {
      console.log('Detection received:', data);

      const newDetection = {
        id: Date.now(),
        bbox: data.bbox || data.bounding_box,
        label: data.label || data.class_name || 'Unknown',
        confidence: data.confidence || 0,
        color: getColorForLabel(data.label || data.class_name),
        timestamp: data.timestamp || new Date().toISOString(),
      };

      setDetections((prev) => [...prev.slice(-9), newDetection]);

      setStats((prev) => ({
        ...prev,
        totalDetections: prev.totalDetections + 1,
        personsDetected:
          newDetection.label.toLowerCase() === 'person'
            ? prev.personsDetected + 1
            : prev.personsDetected,
        objectsDetected:
          newDetection.label.toLowerCase() !== 'person'
            ? prev.objectsDetected + 1
            : prev.objectsDetected,
      }));

      setChartData((prev) => [
        ...prev,
        {
          timestamp: new Date().toISOString(),
          count: 1,
        },
      ]);
    };

    const handleAlert = (data) => {
      console.log('Alert received:', data);

      const newAlert = {
        id: Date.now(),
        type: data.type || data.alert_type || 'detection',
        severity: data.severity || 'medium',
        message: data.message || 'Detection alert',
        confidence: data.confidence,
        metadata: data.metadata,
        timestamp: data.timestamp || new Date().toISOString(),
      };

      setAlerts((prev) => [newAlert, ...prev]);
      setStats((prev) => ({
        ...prev,
        activeAlerts: prev.activeAlerts + 1,
      }));
    };

    const handleStatus = (data) => {
      console.log('Status update:', data);
    };

    socketService.on('connect', handleConnect);
    socketService.on('disconnect', handleDisconnect);
    socketService.on('detection', handleDetection);
    socketService.on('alert', handleAlert);
    socketService.on('status', handleStatus);

    return () => {
      socketService.off('connect', handleConnect);
      socketService.off('disconnect', handleDisconnect);
      socketService.off('detection', handleDetection);
      socketService.off('alert', handleAlert);
      socketService.off('status', handleStatus);
      socketService.disconnect();
    };
  }, []);

  const getColorForLabel = (label) => {
    const colors = {
      person: '#3b82f6',
      hook: '#ef4444',
      load: '#f59e0b',
      crane: '#8b5cf6',
    };
    return colors[label?.toLowerCase()] || '#10b981';
  };

  return (
    <div className="min-h-screen bg-gray-100">
      <header className="bg-white shadow-md">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-6">
          <div className="flex items-center justify-between">
            <div className="flex items-center gap-4">
              <div className="bg-gradient-to-br from-blue-600 to-blue-700 p-3 rounded-lg">
                <Activity className="w-8 h-8 text-white" />
              </div>
              <div>
                <h1 className="text-3xl font-bold text-gray-900">CraneZone-Lite</h1>
                <p className="text-sm text-gray-600 mt-1">
                  AI-powered crane safety monitoring system
                </p>
              </div>
            </div>
            <ConnectionStatus isConnected={isConnected} />
          </div>
        </div>
      </header>

      <main className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6 mb-8">
          <StatsCard
            icon={Activity}
            title="Total Detections"
            value={stats.totalDetections}
            subtitle="All time"
            color="blue"
          />
          <StatsCard
            icon={AlertTriangle}
            title="Active Alerts"
            value={stats.activeAlerts}
            subtitle="Requires attention"
            color="red"
          />
          <StatsCard
            icon={Users}
            title="Persons Detected"
            value={stats.personsDetected}
            subtitle="In danger zone"
            color="orange"
          />
          <StatsCard
            icon={Package}
            title="Objects Detected"
            value={stats.objectsDetected}
            subtitle="Hooks & loads"
            color="green"
          />
        </div>

        <div className="grid grid-cols-1 lg:grid-cols-3 gap-6 mb-8">
          <div className="lg:col-span-2">
            <VideoFeed detections={detections} />
          </div>
          <div>
            <AlertList alerts={alerts} />
          </div>
        </div>

        <div className="mb-8">
          <DetectionChart data={chartData} />
        </div>
      </main>

      <footer className="bg-white border-t border-gray-200 mt-12">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-6">
          <p className="text-center text-sm text-gray-600">
            CraneZone-Lite - Intelligent crane safety monitoring using AI and computer vision
          </p>
        </div>
      </footer>
    </div>
  );
}

export default App;
