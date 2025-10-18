import { useState, useEffect } from 'react';
import { AlertTriangle, Clock, TrendingUp } from 'lucide-react';
import { formatDateTime, getSeverityColor, getSeverityBadge } from '../utils/formatters';

export default function AlertList({ alerts = [] }) {
  const [displayAlerts, setDisplayAlerts] = useState([]);
  const maxDisplay = 10;

  useEffect(() => {
    setDisplayAlerts(alerts.slice(0, maxDisplay));
  }, [alerts]);

  const getAlertIcon = (type) => {
    return <AlertTriangle className="w-5 h-5" />;
  };

  if (alerts.length === 0) {
    return (
      <div className="bg-white rounded-lg shadow-lg p-8">
        <div className="text-center">
          <AlertTriangle className="w-16 h-16 text-gray-300 mx-auto mb-4" />
          <h3 className="text-lg font-semibold text-gray-600 mb-2">No Alerts</h3>
          <p className="text-gray-500">All systems operating normally</p>
        </div>
      </div>
    );
  }

  return (
    <div className="bg-white rounded-lg shadow-lg overflow-hidden">
      <div className="bg-gradient-to-r from-orange-600 to-red-600 px-6 py-4 flex items-center gap-3">
        <AlertTriangle className="w-6 h-6 text-white" />
        <h2 className="text-xl font-bold text-white">Recent Alerts</h2>
        <span className="ml-auto bg-white text-red-600 px-3 py-1 rounded-full text-sm font-bold">
          {alerts.length}
        </span>
      </div>

      <div className="divide-y divide-gray-200 max-h-[600px] overflow-y-auto">
        {displayAlerts.map((alert, index) => (
          <div
            key={alert.id || index}
            className="p-4 hover:bg-gray-50 transition-colors duration-150"
          >
            <div className="flex items-start gap-4">
              <div className={`p-2 rounded-lg ${getSeverityBadge(alert.severity)} text-white`}>
                {getAlertIcon(alert.type)}
              </div>

              <div className="flex-1 min-w-0">
                <div className="flex items-center gap-2 mb-1">
                  <h3 className="font-semibold text-gray-900 text-sm">
                    {alert.message || 'Detection Alert'}
                  </h3>
                  <span
                    className={`px-2 py-0.5 rounded text-xs font-medium border ${getSeverityColor(
                      alert.severity
                    )}`}
                  >
                    {alert.severity?.toUpperCase()}
                  </span>
                </div>

                <div className="text-sm text-gray-600 mb-2">
                  <span className="font-medium">{alert.type || 'Unknown'}</span>
                  {alert.confidence && (
                    <span className="text-gray-500 ml-2">
                      Confidence: {(alert.confidence * 100).toFixed(1)}%
                    </span>
                  )}
                </div>

                {alert.metadata && (
                  <div className="text-xs text-gray-500 mb-2">
                    {Object.entries(alert.metadata).map(([key, value]) => (
                      <span key={key} className="mr-3">
                        {key}: <span className="font-medium">{value}</span>
                      </span>
                    ))}
                  </div>
                )}

                <div className="flex items-center gap-2 text-xs text-gray-500">
                  <Clock className="w-3 h-3" />
                  {formatDateTime(alert.timestamp)}
                </div>
              </div>
            </div>
          </div>
        ))}
      </div>

      {alerts.length > maxDisplay && (
        <div className="bg-gray-50 px-6 py-3 text-center text-sm text-gray-600">
          Showing {maxDisplay} of {alerts.length} alerts
        </div>
      )}
    </div>
  );
}
