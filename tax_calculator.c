#include <stdio.h>

float deductions(float raw_salary){
	return raw_salary - 12550.0;
}

float first_bracket(float income){
	float taxes1 = income * 0.1;
	float fica = income * 0.0765;
	return taxes1 + fica;
}
float second_bracket(float income){
	float taxes1 = 995.0;
	float taxes2 = (income - 9950.0) * 0.12;
	float fica = income * 0.0765;
	return taxes1 + taxes2 + fica;
}
float third_bracket(float income){
	float taxes1 = 4663.88;
	float taxes2 = (income - 40525.0) * 0.22;
	float fica = income * 0.0765;
	return taxes1 + taxes2 + fica;
}
float fourth_bracket(float income){
	float taxes1 = 14750.66;
	float taxes2 = (income - 86375.0) * 0.24;
	float fica = income * 0.0765;
	return taxes1 + taxes2 + fica;
}
float fifth_bracket(float income){
	float taxes1 = 33602.42;
	float taxes2 = (income - 164925.0) * 0.32;
	float fica = income * 0.0765;
	return taxes1 + taxes2 + fica;
}
float sixth_bracket(float income){
	float taxes1 = 47842.10;
	float taxes2 = (income - 209425.0) * 0.35;
	float fica = income * 0.0765;
	return taxes1 + taxes2 + fica;
}
float seventh_bracket(float income){
	float taxes1 = 157803.0;
	float taxes2 = (income - 523600.0) * 0.37;
	float fica = income * 0.0765;
	return taxes1 + taxes2 + fica;
}


float decide_bracket(float taxable_income){
	float final_taxes;
	if(taxable_income <= 9950.0){
		final_taxes = first_bracket(taxable_income);
	}
	else if(taxable_income > 9950.0 && taxable_income <= 40525.0){
		final_taxes = second_bracket(taxable_income);
	}
	else if(taxable_income > 40525.0 && taxable_income <= 86375.0){
		final_taxes = third_bracket(taxable_income);
	}
	else if(taxable_income > 86375.0 && taxable_income <= 164925.0){
		final_taxes = fourth_bracket(taxable_income);
	}
	else if(taxable_income > 164925.0 && taxable_income <= 209425.0){
		final_taxes = fifth_bracket(taxable_income);
	}
	else if(taxable_income > 209425.0 && taxable_income <= 523600.0){
		final_taxes = sixth_bracket(taxable_income);
	}
	else if(taxable_income > 523600.0){
		final_taxes = seventh_bracket(taxable_income);
	}

	return final_taxes;
}

float credits(float pre_credit_taxes, int dependents_1, int dependents_2){
	return pre_credit_taxes - (3600 * dependents_1) - (3000 * dependents_2);
}

int main(){
	float raw_income, taxable_income;
	int dependents_1, dependents_2;
	
	printf("What is your annual income: ");
	scanf("%f", &raw_income);
	
	printf("Dependents between the ages of 0 and 5: ");
	scanf("%d", &dependents_1);

	printf("Dependents between the ages of 6 and 17: ");
	scanf("%d", &dependents_2);

	if(raw_income <= 12550.0){
		taxable_income = raw_income;
	}
	else{
		taxable_income = deductions(raw_income);
	}

	float final_taxes_pre_credits = decide_bracket(taxable_income);
	float final_taxes = credits(final_taxes_pre_credits, dependents_1, dependents_2);

	printf("You owe $%f in taxes.\n", final_taxes);


	return 0;
}
