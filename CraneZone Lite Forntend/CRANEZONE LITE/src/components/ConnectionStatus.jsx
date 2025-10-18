import { Wifi, WifiOff } from 'lucide-react';

export default function ConnectionStatus({ isConnected }) {
  return (
    <div
      className={`flex items-center gap-2 px-4 py-2 rounded-lg ${
        isConnected
          ? 'bg-green-100 text-green-800 border border-green-200'
          : 'bg-red-100 text-red-800 border border-red-200'
      }`}
    >
      {isConnected ? (
        <>
          <Wifi className="w-5 h-5" />
          <span className="font-medium text-sm">Connected to Backend</span>
        </>
      ) : (
        <>
          <WifiOff className="w-5 h-5" />
          <span className="font-medium text-sm">Disconnected</span>
        </>
      )}
    </div>
  );
}
