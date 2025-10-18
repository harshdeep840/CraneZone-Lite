import java.util.Scanner;

class Rectangle {
    double length;
    double breadth;

    void read() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length: ");
        length = scanner.nextDouble();
        System.out.print("Enter breadth: ");
        breadth = scanner.nextDouble();
        scanner.close();
    }

    double calculateArea() {
        return length * breadth;
    }

    double calculatePerimeter() {
        return 2 * (length + breadth);
    }

    void display() {
        System.out.println("Area of the rectangle: " + calculateArea());
        System.out.println("Perimeter of the rectangle: " + calculatePerimeter());
    }

    public static void main(String[] args) {
        Rectangle rect = new Rectangle();
        rect.read();
        rect.display();
    }
}
