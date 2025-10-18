import java.util.Scanner;
class HrsException extends Exception {
    public HrsException(String message) {
        super(message);
    }
}

class MinException extends Exception {
    public MinException(String message) {
        super(message);
    }
}
class SecException extends Exception {
    public SecException(String message) {
        super(message);
    }
}
class Time {
    private int hours;
    private int minutes;
    private int seconds;

    public void setTime() {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter hours: ");
            hours = Integer.parseInt(scanner.nextLine());
            if (hours > 24 || hours < 0) {
                throw new HrsException("Hours should be between 0 and 24");
            }

            System.out.print("Enter minutes: ");
            minutes = Integer.parseInt(scanner.nextLine());
            if (minutes > 60 || minutes < 0) {
                throw new MinException("Minutes should be between 0 and 60");
            }

            System.out.print("Enter seconds: ");
            seconds = Integer.parseInt(scanner.nextLine());
            if (seconds > 60 || seconds < 0) {
                throw new SecException("Seconds should be between 0 and 60");
            }
        } catch (HrsException | MinException | SecException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class q9 {
    public static void main(String[] args) {
        Time time = new Time();
        time.setTime();
    }
}            