import java.util.Scanner;

public static class SplitString {

    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        System.out.println("Enter the string : ");
        String str = sc.nextLine();
        System.out.println("you have entered : "+str);
        for (String val : str.split("-", 2)) {
            System.out.println(val);
        }
        for (String st : str.split("-")) {
            System.out.println(st);
        }
    }
}