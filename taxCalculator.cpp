#include <iostream>
using namespace std;

double fica = 0.0765;


float deductions(double rawIncome){
    double postDeductionSalary = rawIncome - 12400;
    return postDeductionSalary;
}
float firstBracket(double taxableIncome){
    double taxes1 = taxableIncome * 0.10;
    double taxesFinal = taxes1 + (taxableIncome * fica);
    return taxesFinal;
}
float secondBracket(double taxableIncome){
    double taxes1 = 987.50;
    double taxes2 = (taxableIncome - taxes1) * 0.12;
    double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica);
    return taxesFinal;
}
float thirdBracket(double taxableIncome){
    double taxes1 = 4617.50;
    double taxes2 = (taxableIncome - taxes1) * 0.22;
    double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica);
    return taxesFinal;
}
float fourthBracket(double taxableIncome){
    double taxes1 = 14605.50;
    double taxes2 = (taxableIncome - taxes1) * 0.24;
    double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica);
    return taxesFinal;
}
float fifthBracket(double taxableIncome){
    double taxes1 = 33271.50;
    double taxes2 = (taxableIncome - taxes1) * 0.32;
    double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica);
    return taxesFinal;
}
float sixthBracket(double taxableIncome){
    double taxes1 = 47367.50;
    double taxes2 = (taxableIncome - taxes1) * 0.35;
    double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica);
    return taxesFinal;
}
float seventhBracket(double taxableIncome){
    double taxes1 = 156235;
    double taxes2 = (taxableIncome - taxes1) * 0.37;
    double taxesFinal = taxes1 + taxes2 + (taxableIncome * fica);
    return taxesFinal;
}
float taxCredits(double preCreditTaxes, double depn1, double depn2){
    double credits = (2000 * depn1) + (500 * depn2);
    double postCreditTaxes = preCreditTaxes - credits;
    return postCreditTaxes;
}
float chooseBracket(double z){
    if(z <= 9875){
        return firstBracket(z);
    }
    else if (z >= 9876 && z <= 40125) {
        return secondBracket(z);
    }
    else if (z >= 40126 && z <= 85525) {
        return thirdBracket(z);
    }
    else if (z >= 85526 && z <= 163300) {
        return fourthBracket(z);
    }
    else if (z >= 163301 && z <= 207350) {
        return fifthBracket(z);
    }
    else if (z >= 207351 && z <= 518400) {
        return sixthBracket(z);
    }
    else if (z >= 518401) {
        return seventhBracket(z);
    }
}



int main(){
    double salaryInput;
    int dependents1Input,dependents2Input;
    cout << "What is your raw income: ";
    cin >> salaryInput;
    if(salaryInput < 12400){
        cout << "You are not eligible for a tax return";
        return 0;

    }



    cout << "How many dependents do you have 16 or younger: ";
    cin >> dependents1Input;
    cout << "How many dependents do you have 17 or older: ";
    cin >> dependents2Input;

    double taxableIncome = deductions(salaryInput);
    double taxBeforeCredits = chooseBracket(taxableIncome);
    double postCreditTaxes = taxCredits(taxBeforeCredits, dependents1Input, dependents2Input);

    cout << "You owe $" << postCreditTaxes << " in taxes.";
    
    return 0;
}