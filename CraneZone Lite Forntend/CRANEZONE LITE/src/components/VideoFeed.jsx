import { useEffect, useRef, useState } from 'react';
import { API_CONFIG } from '../config/config';
import { Camera, AlertCircle } from 'lucide-react';

export default function VideoFeed({ detections = [] }) {
  const canvasRef = useRef(null);
  const [imageLoaded, setImageLoaded] = useState(false);
  const [error, setError] = useState(null);

  const videoStreamUrl = `${API_CONFIG.BACKEND_URL}${API_CONFIG.VIDEO_STREAM_PATH}`;

  useEffect(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;

    const ctx = canvas.getContext('2d');
    const img = new Image();

    img.onload = () => {
      canvas.width = img.width;
      canvas.height = img.height;
      ctx.drawImage(img, 0, 0);
      setImageLoaded(true);
      setError(null);

      drawDetections(ctx, detections, img.width, img.height);
    };

    img.onerror = () => {
      setError('Failed to load video stream');
      setImageLoaded(false);
    };

    img.src = videoStreamUrl + '?t=' + new Date().getTime();

    const interval = setInterval(() => {
      img.src = videoStreamUrl + '?t=' + new Date().getTime();
    }, 100);

    return () => clearInterval(interval);
  }, [videoStreamUrl]);

  useEffect(() => {
    const canvas = canvasRef.current;
    if (!canvas || !imageLoaded) return;

    const ctx = canvas.getContext('2d');
    drawDetections(ctx, detections, canvas.width, canvas.height);
  }, [detections, imageLoaded]);

  const drawDetections = (ctx, detections, width, height) => {
    detections.forEach((detection) => {
      const { bbox, label, confidence, color } = detection;

      if (!bbox || bbox.length !== 4) return;

      const [x1, y1, x2, y2] = bbox;

      ctx.strokeStyle = color || '#ff0000';
      ctx.lineWidth = 3;
      ctx.strokeRect(x1, y1, x2 - x1, y2 - y1);

      ctx.fillStyle = color || '#ff0000';
      ctx.fillRect(x1, y1 - 25, (label.length + confidence.toString().length) * 8 + 20, 25);

      ctx.fillStyle = '#ffffff';
      ctx.font = 'bold 14px Arial';
      ctx.fillText(`${label} ${(confidence * 100).toFixed(0)}%`, x1 + 5, y1 - 7);
    });
  };

  return (
    <div className="bg-white rounded-lg shadow-lg overflow-hidden">
      <div className="bg-gradient-to-r from-blue-600 to-blue-700 px-6 py-4 flex items-center gap-3">
        <Camera className="w-6 h-6 text-white" />
        <h2 className="text-xl font-bold text-white">Live Video Feed</h2>
        <div className="ml-auto flex items-center gap-2">
          <div className="w-3 h-3 bg-green-400 rounded-full animate-pulse"></div>
          <span className="text-sm text-white font-medium">LIVE</span>
        </div>
      </div>

      <div className="p-4 bg-gray-50">
        <div className="relative bg-black rounded-lg overflow-hidden" style={{ minHeight: '400px' }}>
          {error && (
            <div className="absolute inset-0 flex items-center justify-center bg-gray-900">
              <div className="text-center">
                <AlertCircle className="w-16 h-16 text-red-500 mx-auto mb-4" />
                <p className="text-white text-lg mb-2">Video Stream Unavailable</p>
                <p className="text-gray-400 text-sm">
                  Make sure your backend is running at {API_CONFIG.BACKEND_URL}
                </p>
              </div>
            </div>
          )}

          <canvas
            ref={canvasRef}
            className="w-full h-auto"
            style={{ display: error ? 'none' : 'block' }}
          />
        </div>

        <div className="mt-4 flex items-center justify-between text-sm text-gray-600">
          <span>Detections: {detections.length}</span>
          <span className="text-xs text-gray-500">Stream URL: {videoStreamUrl}</span>
        </div>
      </div>
    </div>
  );
}
