from Tkinter import *
import Tkinter as tk


fica = 0.0765
def deductions(rawIncome):
    rawTaxableIncome = rawIncome - 12400
    return rawTaxableIncome
def firstBracket(taxableIncome):
    taxes1 = taxableIncome * 0.10
    taxesFinal = taxes1 + (taxableIncome * fica)
    return taxesFinal
def secondBracket(taxableIncome):
    taxes1 = 987.50
    taxes2 = (taxableIncome - taxes1) * 0.12
    taxesFinal = taxes1 + taxes2 + (taxableIncome * fica)
    return taxesFinal
def thirdBracket(taxableIncome):
    taxes1 = 4617.50
    taxes2 = (taxableIncome - taxes1) * 0.22
    taxesFinal = taxes1 + taxes2 + (taxableIncome * fica)
    return taxesFinal
def fourthBracket(taxableIncome):
    taxes1 = 14605.50
    taxes2 = (taxableIncome - taxes1) * 0.24
    taxesFinal = taxes1 + taxes2 + (taxableIncome * fica)
    return taxesFinal
def fifthBracket(taxableIncome):
    taxes1 = 33271.50
    taxes2 = (taxableIncome - taxes1) * 0.32
    taxesFinal = taxes1 + taxes2 + (taxableIncome * fica)
    return taxesFinal
def sixthBracket(taxableIncome):
    taxes1 = 47367.50
    taxes2 = (taxableIncome - taxes1) * 0.35
    taxesFinal = taxes1 + taxes2 + (taxableIncome * fica)
    return taxesFinal
def seventhBracket(taxableIncome):
    taxes1 = 156235
    taxes2 = (taxableIncome - taxes1) * 0.37
    taxesFinal = taxes1 + taxes2 + (taxableIncome * fica)
    return taxesFinal
def taxCredits(preCreditTaxes, depn1, depn2):
    credits = (2000 * depn1) + (500 * depn2)
    postCreditTaxes = preCreditTaxes - credits
    return postCreditTaxes
def whichBracket(z):
    if z <= 9875:
        beforeCreditTaxes = firstBracket(z)
        return beforeCreditTaxes
    elif z >= 9876 and z <= 40125:
        beforeCreditTaxes = secondBracket(z)
        return beforeCreditTaxes
    elif z >= 40126 and z <= 85525:
        beforeCreditTaxes = thirdBracket(z)
        return beforeCreditTaxes
    elif z >= 85526 and z <= 163300:
        beforeCreditTaxes = fourthBracket(z)
        return beforeCreditTaxes
    elif z >= 163301 and z <= 207350:
        beforeCreditTaxes = fifthBracket(z)
        return beforeCreditTaxes
    elif z >= 207351 and z <= 518400:
        beforeCreditTaxes = sixthBracket(z)
        return beforeCreditTaxes
    elif z >= 518401:
        beforeCreditTaxes = seventhBracket(z)
        return beforeCreditTaxes


def main():
    global answer1
    global answer2


    x = 1
    preDeductionIncome = int(incomeEntry.get())
    dependents1 = int(depn1Entry.get())
    dependents2 = int(depn2Entry.get())

    if preDeductionIncome < 12400:
        answer1 = tk.Label(root, text="You do not make enough to file taxes.")
        answer1.grid(row=4)
        return
    elif preDeductionIncome >= 12400:
        x = x

    taxableIncome = deductions(preDeductionIncome)
    taxBeforeCredits = whichBracket(taxableIncome)
    postCreditTaxes = taxCredits(taxBeforeCredits, dependents1, dependents2)

    if postCreditTaxes >= 0:
        answer1 = tk.Label(root, text="You owe $" + str(postCreditTaxes) + " in taxes.")
        answer1.grid(row=4)
        return
    elif postCreditTaxes < 0:
        postCreditTaxes = postCreditTaxes * -1
        answer1 = tk.Label(root, text="You owe $0 in taxes.")
        answer1.grid(row=4)
        answer2 = tk.Label(root, text="You get $" + str(postCreditTaxes) + " from the government.")
        answer2.grid(row=5)


def clear():
    answer1.destroy()
    answer2.destroy()




root = Tk()

root.resizable(False, False)
root.title("Tax Calculator")
root.geometry("500x400")

incomeLabel = tk.Label(root, text="Raw Income")
incomeLabel.grid(row=0, column=0)
incomeEntry = tk.Entry(root)
incomeEntry.grid(row=0, column=1)

depn1Label = tk.Label(root, text="Dependents 16 And Younger")
depn1Label.grid(row=1, column=0)
depn1Entry = tk.Entry(root)
depn1Entry.grid(row=1, column=1)

depn2Label = tk.Label(root, text="Dependents 17 And Older")
depn2Label.grid(row=2, column=0)
depn2Entry = tk.Entry(root)
depn2Entry.grid(row=2, column=1)

submitButton = Button(root, text="Submit", command=main)
submitButton.grid(row=3, column=0)

clearButton = Button(root, text="clear", command=clear)
clearButton.grid(row=6)



root.mainloop()