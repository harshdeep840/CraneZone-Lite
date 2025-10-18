class MathOperations {
    public int subtract(int a, int b) {
        return a - b;
    }

    public double subtract(double a, double b) {
        return a - b;
    }

    public int subtract(int a, int b, int c) {
        return a - b - c;
    }

    public int subtract(int[] numbers) {
        int result = 0;
        for (int num : numbers) {
            result -= num;
        }
        return result;
    }
}

public class Mathoperationsdemo {
    public static void main(String[] args) {
        MathOperations mathOps = new MathOperations();

        int result1 = mathOps.subtract(10, 5);
        System.out.println("Subtraction Result (int): " + result1);

        double result2 = mathOps.subtract(7.5, 2.5);
        System.out.println("Subtraction Result (double): " + result2);

        int result3 = mathOps.subtract(20, 5, 3);
        System.out.println("Subtraction Result (int): " + result3);

        int[] numbers = {8, 2, 1};
        int result4 = mathOps.subtract(numbers);
        System.out.println("Subtraction Result (int array): " + result4);
    }
}
