export const API_CONFIG = {
  BACKEND_URL: import.meta.env.VITE_BACKEND_URL || 'http://localhost:8000',
  SOCKET_URL: import.meta.env.VITE_SOCKET_URL || 'http://localhost:8000',
  VIDEO_STREAM_PATH: '/video/stream',
  RECONNECTION_DELAY: 3000,
  MAX_ALERTS_DISPLAY: 50,
};

export const DETECTION_TYPES = {
  HOOK: 'hook',
  LOAD: 'load',
  PERSON: 'person',
  INTRUSION: 'intrusion',
};

export const ALERT_SEVERITY = {
  LOW: 'low',
  MEDIUM: 'medium',
  HIGH: 'high',
  CRITICAL: 'critical',
};
