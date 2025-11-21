#include <stdio.h>

int main() {
    int birth_year, age , option;
    float Basic_Exemption_Limit, redcution=0 , TTincome, Special_Income, income, sec112 = 0, sec112A = 0, sec111A = 0, Casual_Income = 0;
    float tax1 = 0, tax2 = 0, tax3 = 0, tax4 = 0, Special_tax = 0, tax = 0, rebate = 0, TotalTax = 0;
    float surcharge , First_quarter = 0, Second_quarter = 0, Third_quarter = 0, Fourth_quarter = 0;
    char* slab ;

    printf("Enter your birth year: ");
    scanf("%d", &birth_year);
    age = 2025 - birth_year;

    printf("WHETHER OPTING OUT NEW TAX REGIME OF SECTION 115BAC (FOR YES :0 OR FOR NO: 1 )");
    scanf("%s",&option);

//TOTAL INCOME AFTER DEDUCTIONS u/s 80C-80U
    
    printf("Enter your taxable total income (in Rs): ");
    scanf("%f", &TTincome);

    printf("Income under section 111A, 112A, 112 and Casual income:\n");
    scanf("%f", &Special_Income);
    income = TTincome - Special_Income;

// OLD REGIME
if (option == 0) {
    // Special Rate for Capital Gains
        if (age < 60) {
            Basic_Exemption_Limit = 250000; }
        else if (age >= 60 && age < 80) {
            Basic_Exemption_Limit = 300000; }
        else {
            Basic_Exemption_Limit = 500000;}


        if (income < Basic_Exemption_Limit) {
            redcution = Basic_Exemption_Limit - income;
            income = 0;}

        if (Special_Income > 0) {
            printf("Enter special income u/s 112: ");
            scanf("%f", &sec112);
            tax1 = (sec112 - redcution) * 0.125;
            printf("tax on112 :%.2f\n",tax1);

            printf("Enter special income u/s 112A: ");
            scanf("%f", &sec112A);
            tax2 = (sec112A > 125000) ? (sec112A - 125000) * 0.125 : 0;  // Rate is 12.5% above Rs 1L for equity
            printf("tax on112A :%.2f\n",tax2);

            printf("Enter special income u/s 111A: ");
            scanf("%f", &sec111A);
            tax3 = sec111A * 0.20; // STCG rate on shares is 20%
            printf("tax on111A :%.2f\n",tax3);

            printf("Enter casual income: ");
            scanf("%f", &Casual_Income);
            tax4 = Casual_Income * 0.30;
            printf("tax on casual :%.2f\n",tax4);

            Special_tax = tax1 + tax2 + tax3 + tax4;
        }

    // TAX CALCULATION ON NORMAL INCOMES

    //AGE LESS THAN 60
        if (age < 60) {
            if (income <= 250000) {
                tax = 0;
                slab = "Nil (Up to Rs. 2,50,000)";
            } 
            else if (income <= 500000) {
                tax = (income - 250000) * 0.05;
                slab = "5 percent (Rs. 2,50,001 - Rs. 5,00,000)";
            } 
            else if (income <= 1000000) {
                tax = 12500 + (income - 500000) * 0.20;
                slab = "20 percent (Rs. 5,00,001 - Rs. 10,00,000)";
            }
            else {
                tax = 112500 + (income - 1000000) * 0.30;
                slab = "30 percent (Above Rs. 10,00,000)";
            }
        }

    // AGE MORE THAN EQUAL TO 60 AND LESS THAN 80

        else if (age >= 60 && age < 80) {
            if (income <= 300000) {
                tax = 0;
                slab = "Nil (Up to Rs. 3,00,000)";
            } else if (income <= 500000) {
                tax = (income - 300000) * 0.05;
                slab = "5 percent (Rs. 3,00,001 - Rs. 5,00,000)";
            } else if (income <= 1000000) {
                tax = 10000 + (income - 500000) * 0.20;
                slab = "20 percent (Rs. 5,00,001 - Rs. 10,00,000)";
            } else {
                tax = 110000 + (income - 1000000) * 0.30;
                slab = "30 percent (above Rs. 10,00,000)";
            }
        }

    // AGE MORE THAN OR EQUAL TO 80
        else {
            if (income <= 500000) {
                tax = 0;
                slab = "Nil (Up to Rs. 5,00,000)";
            } else if (income <= 1000000) {
                tax = (income - 500000) * 0.20;
                slab = "20 Percent (Rs. 5,00,001 - Rs. 10,00,000)";
            } else {
            tax = 100000 + (income - 1000000) * 0.30;
            slab = "30 Percent above 10,00,000";
            }
        }

    //TOTAL TAX BEFORE MARGINAL RELIEF , SURCHARGE AND REBATE
        TotalTax = tax + Special_tax;
        printf("total tax before marginal relief , surcharge and rebate :%.2f\n",TotalTax);

    //MARGINAL RELIEF
        if (TTincome > 5000000 && TTincome <= 10000000) {
            if (TotalTax-1312500 > TTincome - 5000000) {
                TotalTax = TotalTax - ((TotalTax-1312500) - (TTincome - 5000000));}
        }
        else if (TTincome > 10000000 && TTincome <= 20000000) {
            if (TotalTax - 3217500 > TTincome - 10000000) {
                TotalTax = TotalTax - ((TotalTax-3217500) - (TTincome - 10000000));}
        }
        else if (TTincome > 20000000 && TTincome <= 50000000) {
            if (TotalTax - 6951750 > TTincome - 20000000) {
                TotalTax = TotalTax - ((TotalTax-6951750) - (TTincome - 20000000));}
        }
        else if (TTincome > 50000000) {
            if (TotalTax - 19256248 > TTincome - 500000001) {
                TotalTax = TotalTax - ((TotalTax-19256248) - (TTincome - 500000001));}
        }

    //SURCHARGE
    
        printf("\ntotal tax before surcharge and cess :%.2f\n",TotalTax);
        if (TTincome > 5000000 && TTincome <= 10000000) {
            TotalTax = TotalTax * 1.10;
        }
        else if (TTincome > 10000000 && TTincome <= 20000000) {
            TotalTax = TotalTax * 1.15;
        }
        else if (TTincome > 20000000 && TTincome <= 50000000) {
            tax = tax * 1.25;
            Special_tax = Special_tax *  1.15;
            TotalTax = tax + Special_tax;
        }
        else if (TTincome > 50000000) {
            tax = tax * 1.37;
            Special_tax = Special_tax *  1.15;
            TotalTax = tax + Special_tax;
        }
        printf("\ntotal tax after surcharge and before cess :%.2f\n",TotalTax);
    
    // Section 87A rebate
        if (income > 0 && income <= 500000) {
            rebate = ((TotalTax - tax2) >= 12500 ? 12500 : TotalTax);  //REBATE ON SEC112A IS NOT ALLOWED
            TotalTax -= rebate;
        }
    }
    
// NEW REGIME
else {
    Basic_Exemption_Limit = 400000;

    if (income < Basic_Exemption_Limit) {
            redcution = Basic_Exemption_Limit - income;
            income = 0;}

    if (Special_Income > 0) {
        printf("Enter special income u/s 112: ");
        scanf("%f", &sec112);
        tax1 = (sec112 - redcution) * 0.125;
        printf("tax on112 :%.2f\n",tax1);

        printf("Enter special income u/s 112A: ");
        scanf("%f", &sec112A);
        tax2 = (sec112A > 125000) ? (sec112A - 125000) * 0.125 : 0;  // Rate is 12.5% above Rs 1L for equity
        printf("tax on112A :%.2f\n",tax2);

        printf("Enter special income u/s 111A: ");
        scanf("%f", &sec111A);
        tax3 = sec111A * 0.20; // STCG rate on shares is 20%
        printf("tax on111A :%.2f\n",tax3);

        printf("Enter casual income: ");
        scanf("%f", &Casual_Income);
        tax4 = Casual_Income * 0.30;
        printf("tax on casual :%.2f\n",tax4);

        Special_tax = tax1 + tax2 + tax3 + tax4;
        }
    // TAX CALCULATION ON NORMAL INCOMES

    // REGARDLESS OF AGE GROUP 

        if (income <= 400000) {
            tax = 0;
            slab = "Nil (Up to Rs. 4,00,000)";
        } 
        else if (income <= 800000) {
            tax = (income - 400000) * 0.05;
            slab = "5 percent (Rs. 4,00,001 - Rs. 8,00,000)";
        } 
        else if (income <= 1200000) {
            tax = 20000 + (income - 800000) * 0.10;
            slab = "10 percent (Rs. 8,00,001 - Rs. 12,00,000)";
        }
        else if (income <= 1600000) {
            tax = 60000 + (income - 1200000) * 0.15;
            slab = "15 percent (Rs. 12,00,001 - Rs. 16,00,000)";
        }
        else if (income <= 2000000) {
            tax = 120000 + (income - 1600000) * 0.20;
            slab = "20 percent (Rs. 16,00,001 - Rs. 20,00,000)";
        }
        else if (income <= 2400000) {
            tax = 200000 + (income - 2000000) * 0.25;
            slab = "20 percent (Rs. 20,00,001 - Rs. 24,00,000)";
        }
        else {
            tax = 300000 + (income - 2400000) * 0.30;
            slab = "30 percent (Above Rs. 24,00,000)";
        }
        

    //TOTAL TAX BEFORE MARGINAL RELIEF , SURCHARGE AND REBATE
        TotalTax = tax + Special_tax;
        printf("total tax before marginal relief , surcharge and rebate :%.2f\n",TotalTax);

    //MARGINAL RELIEF
        if (TTincome > 5000000 && TTincome <= 10000000) {
            if (TotalTax - 1080000 > TTincome - 5000000) {
                TotalTax = TotalTax - ((TotalTax-1080000) - (TTincome - 5000000));}
        }
        else if (TTincome > 10000000 && TTincome <= 20000000) {
            if (TotalTax - 2580000 > TTincome - 10000000) {
                TotalTax = TotalTax - ((TotalTax-2580000) - (TTincome - 10000000));}
        }
        else if (TTincome > 20000000) {
            if (TotalTax - 5580000 > TTincome - 200000001) {
                TotalTax = TotalTax - ((TotalTax-5580000) - (TTincome - 200000001));}
        }

    //SURCHARGE
    
        printf("\ntotal tax before surcharge and cess :%.2f\n",TotalTax);
        if (TTincome > 5000000 && TTincome <= 10000000) {
            TotalTax = TotalTax * 1.10;
        }
        else if (TTincome > 10000000 && TTincome <= 20000000) {
            TotalTax = TotalTax * 1.15;
        }
        else if (TTincome > 20000000) {
            tax = tax * 1.25;
            Special_tax = Special_tax *  1.15;
            TotalTax = tax + Special_tax;
        }
        printf("\ntotal tax after surcharge and before cess :%.2f\n",TotalTax);

    // Section 87A rebate
        if (income > 0 && income <= 1200000) {
            rebate = ((TotalTax - tax2) >= 25000 ? 25000 : TotalTax);  //REBATE ON SEC112A IS NOT ALLOWED
            TotalTax -= rebate;
        }
    
    }
    // Health and Education cess
    TotalTax *= 1.04;
    printf("\ntotal tax after surcharge and cess :%.2f\n",TotalTax);



    printf("\nAnnual Income Entered: Rs %.2f", TTincome);
    printf("\nTax Slab Applied: %s", slab);
    printf("\nTax Before Rebate: Rs %.2f", TotalTax + rebate);
    printf("\nRebate Applied: Rs %.2f", rebate);
    printf("\nTax Payable: Rs %.2f\n", TotalTax);

    First_quarter = TotalTax * 0.15;
    Second_quarter = TotalTax * 0.30;
    Third_quarter = TotalTax * 0.30;
    Fourth_quarter = TotalTax * 0.25;

    printf("Tax payable on or before 15 June: %.2f\n", First_quarter);
    printf("Tax payable on or before 15 September: %.2f\n", Second_quarter);
    printf("Tax payable on or before 15 December: %.2f\n", Third_quarter);
    printf("Tax payable on or before 15 March: %.2f\n", Fourth_quarter);

    return 0;
}