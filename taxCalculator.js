var fica = 0.0765;

function main() {

  //This is the salary that you are using
  var question1 = 50000;
  //this is the number of dependents 16 and under
  var question2 = 1;
  //this is the number of dependents 17 and older
  var question3 = 0;

  if (question1 >= 12400) {
  } else {
    console.log("You are not able to file a tax return.");
    return;
  }
  var postDeductionTaxes = deductions(question1);
  var beforeCreditTaxes = bracketChoice(postDeductionTaxes);
  var finalTaxes = taxCredits(beforeCreditTaxes, question2, question3);
  console.log("You have to pay $" + finalTaxes + " in taxes.");
}

function deductions(rawIncome) {
  return rawIncome - 12400;
}

function bracketChoice(incomeBeingTaxed) {
  if (incomeBeingTaxed <= 9875) {
    var taxes = bracket1(incomeBeingTaxed);
    return taxes;
  } else if (incomeBeingTaxed >= 9876 && incomeBeingTaxed <= 40125) {
    var taxes = bracket2(incomeBeingTaxed);
    return taxes;
  } else if (incomeBeingTaxed >= 40126 && incomeBeingTaxed <= 85525) {
    var taxes = bracket3(incomeBeingTaxed);
    return taxes;
  } else if (incomeBeingTaxed >= 85526 && incomeBeingTaxed <= 163300) {
    var taxes = bracket4(incomeBeingTaxed);
    return taxes;
  } else if (incomeBeingTaxed >= 163301 && incomeBeingTaxed <= 207350) {
    var taxes = bracket5(incomeBeingTaxed);
    return taxes;
  } else if (incomeBeingTaxed >= 207351 && incomeBeingTaxed <= 518400) {
    var taxes = bracket6(incomeBeingTaxed);
    return taxes;
  } else if (incomeBeingTaxed >= 518401) {
    var taxes = bracket7(incomeBeingTaxed);
    return taxes;
  }
}
function taxCredits(preCreditTaxes, secondQuestion, thirdQuestion) {
  var credits = 2000 * secondQuestion + 500 * thirdQuestion;
  var totalTaxes = preCreditTaxes - credits;
  return totalTaxes;
}

function bracket1(taxableIncome) {
  var taxes1 = taxableIncome * 0.1;
  var taxesFinal = taxes1 + taxableIncome * fica;
  return taxesFinal;
}
function bracket2(taxableIncome) {
  var taxes1 = 987.5;
  var taxes2 = (taxableIncome - taxes1) * 0.12;
  var taxesFinal = taxes1 + taxes2 + taxableIncome * fica;
  return taxesFinal;
}
function bracket3(taxableIncome) {
  var taxes1 = 4617.5;
  var taxes2 = (taxableIncome - taxes1) * 0.22;
  var taxesFinal = taxes1 + taxes2 + taxableIncome * fica;
  return taxesFinal;
}
function bracket4(taxableIncome) {
  var taxes1 = 14605.5;
  var taxes2 = (taxableIncome - taxes1) * 0.24;
  var taxesFinal = taxes1 + taxes2 + taxableIncome * fica;
  return taxesFinal;
}
function bracket5(taxableIncome) {
  var taxes1 = 33271.5;
  var taxes2 = (taxableIncome - taxes1) * 0.32;
  var taxesFinal = taxes1 + taxes2 + taxableIncome * fica;
  return taxesFinal;
}
function bracket6(taxableIncome) {
  var taxes1 = 47367.5;
  var taxes2 = (taxableIncome - taxes1) * 0.35;
  var taxesFinal = taxes1 + taxes2 + taxableIncome * fica;
  return taxesFinal;
}
function bracket7(taxableIncome) {
  var taxes1 = 156235;
  var taxes2 = (taxableIncome - taxes1) * 0.37;
  var taxesFinal = taxes1 + taxes2 + taxableIncome * fica;
  return taxesFinal;
}

