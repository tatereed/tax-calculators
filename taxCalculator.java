import java.util.Scanner;
import javax.swing.*;

public class taxCalculator {
    double fica = 0.0765;


    static double deductions(double rawincome){
        double x = rawincome - 12400.0;
        return x;
    }
    static double firstBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = taxableIncome * 0.10;
        double taxesFinal = taxes1 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double secondBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = 987.50;
        double taxes2 = (taxableIncome - taxes1) * 0.12;
        double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double thirdBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = 4617.50;
        double taxes2 = (taxableIncome - taxes1) * 0.22;
        double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double fourthBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = 14605.50;
        double taxes2 = (taxableIncome - taxes1) * 0.24;
        double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double fifthBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = 33271.50;
        double taxes2 = (taxableIncome - taxes1) * 0.32;
        double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double sixthBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = 47367.50;
        double taxes2 = (taxableIncome - taxes1) * 0.35;
        double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double seventhBracket(double taxableIncome){
        taxCalculator fica = new taxCalculator();
        double taxes1 = 156235;
        double taxes2 = (taxableIncome - taxes1) * 0.37;
        double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica.fica);
        return taxesFinal;
    }
    static double taxCredit(double preCreditTaxes, int depn1, int depn2){
        double credits = (2000 * depn1) + (500 * depn2);
        double postCreditTaxes = preCreditTaxes - credits;
        return postCreditTaxes;
    }
    static double chooseBracket(double z){
        double beforeCreditTaxes;
        if(z <= 9875) {
            beforeCreditTaxes = firstBracket(z);
            return beforeCreditTaxes;
        }
        else if (z >= 9876 && z <= 40125) {
            beforeCreditTaxes = secondBracket(z);
            return beforeCreditTaxes;
        }
        else if (z >= 40126 && z <= 85525) {
            beforeCreditTaxes = thirdBracket(z);
            return beforeCreditTaxes;
        }
        else if (z >= 85526 && z <= 163300) {
            beforeCreditTaxes = fourthBracket(z);
            return beforeCreditTaxes;
        }
        else if (z >= 163301 && z <= 207350) {
            beforeCreditTaxes = fifthBracket(z);
            return beforeCreditTaxes;
        }
        else if (z >= 207351 && z <= 518400) {
            beforeCreditTaxes = sixthBracket(z);
            return beforeCreditTaxes;
        }
        else if (z >= 518401) {
            beforeCreditTaxes = seventhBracket(z);
            return beforeCreditTaxes;
        }
        return 0;
    }



    public static void main(String[] args){
        Scanner input1 = new Scanner(System.in);
        Scanner input3 = new Scanner(System.in);
        Scanner input4 = new Scanner(System.in);

        System.out.print("What is your raw income: $");
        double rawIncome = input1.nextDouble();
        if(rawIncome >= 12400.0){
        }
        else{
            System.out.println("You are not eligible for a tax return.");
            System.exit(0);
        }


        System.out.print("Number of Dependents 16 and under: ");
        int question2 = input3.nextInt();
        System.out.print("Number of Dependents over 16: ");
        int question3 = input4.nextInt();


        double taxableIncome = deductions(rawIncome);
        double taxBeforeCredits = chooseBracket(taxableIncome);
        double postCreditTaxes = taxCredit(taxBeforeCredits, question2, question3);

        System.out.println("You owe $" + postCreditTaxes + " in taxes");

    }
}
