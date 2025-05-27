#include<stdio.h>
#include<string.h>

void create_account();
void send_money();
void mobile_recharge();
void payment();
void cash_in();
void pay_bill();
void my_bkash();

const char* BKASH = "bkash.dat";

struct bkash
{
    char name[50];
    int phone_number;
    float balance;
};

int main()
{
    char password[20];
    char correctPassword[] = "nahin";

    printf("\t\t\t\t*** Enter password to access the system: ");
    scanf("%s", password);

    if (strcmp(password, correctPassword) == 0)
    {
        printf("\n\n\t\t\t\t\t*****Access Granted*****\n");
        printf("\t\t\t\t\t________________________\n");
        printf("\nRedirecting to the system....\n");
        while (1)
        {
            int a;
            printf("\n---------------------------------------------------------------\n");
            printf("Welcome to bKash. Don't share your OTP or password with anyone!");
            printf("\n---------------------------------------------------------------\n");
            printf("1. Send Money\n");
            printf("2. Mobile Recharge\n");
            printf("3. Payment\n");
            printf("4. Cash In\n");
            printf("5. Pay Bill\n");
            printf("6. My bKash\n");
            printf("7. Helpline\n");
            printf("8. Create New Account\n");
            printf("9. Exit\n");
            printf("Enter any option: ");
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                send_money();
                break;
            case 2:
                mobile_recharge();
                break;
            case 3:
                payment();
                break;
            case 4:
                cash_in();
                break;
            case 5:
                pay_bill();
                break;
            case 6:
                my_bkash();
                break;
            case 7:
                printf("Helpline number: 16247....\n");
                break;
            case 8:
                create_account();
                break;
            case 9:
                printf("\033[1;36mExiting....\nThanks for with bKash.\033[0m\n");
                printf("\033[1;32mDeveloped by: Nahin Ur Roshid Durjoy\033[0m\n");
                printf("\033[1;32mnahinurroshiddurjoy@gmail.com\033[0m");

                return 0;
                break;
            default:
                printf("\033[1;31mEntered Wrong Option. Please Try Again!\n\033[0m\n");

            }
        }
    }
    else
    {
        printf("\033[1;31m\n\t\t\t\t\tAccess denied. Wrong password.\n\033[0m\n");
    }
}

void create_account()
{
    struct bkash a1;
    FILE *file = fopen(BKASH,"ab+");
    if (file == NULL)
    {
        printf("\nUnable to open file!");
        return;
    }

    char c;
    do
    {
        c = getchar();
    }
    while(c != '\n' && c != EOF);
    printf("\nEnter your name: ");
    fgets(a1.name, sizeof(a1.name),stdin);
    int index1= strcspn(a1.name, "\n");
    a1.name[index1] = '\0';
    printf("Enter your phone number: ");
    scanf("%d",&a1.phone_number);
    a1.balance = 0;


    fwrite(&a1, sizeof(a1), 1, file);
    fclose(file);
    printf("\nAccount Created Successfully!");
}

void send_money()
{
    FILE *file = fopen(BKASH, "rb+");
    if(file == NULL)
    {
        printf("\nUnable to open account file!");
        return;
    }

    int acc_no;
    float amount;
    int refno;
    struct bkash accr;
    printf("Enter your Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter Receiver bKash Account Number: ");
    scanf("%d", &refno);
    printf("Enter the amount: ");
    scanf("%f", &amount);
    while (fread(&accr, sizeof(accr), 1, file))
    {
        if (accr.phone_number == acc_no)
        {
            if (accr.balance >= amount)
            {
                accr.balance -= amount;
                fseek(file, -sizeof(accr), SEEK_CUR);
                fwrite(&accr, sizeof(accr), 1, file);
                printf("\nYour send money BDT.%.2f to number 0%d is Successful.\nNew Balance is BDT.%.2f",amount,refno,accr.balance);
            }
            else
            {
                printf("Insufficient balance!");
            }
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Send money is not successful. Phone number 0%d doesn't matched...",acc_no);


}
void mobile_recharge()
{
    FILE *file = fopen(BKASH, "rb+");
    if(file == NULL)
    {
        printf("\nUnable to open account file!");
        return;
    }

    int acc_no;
    float amount;
    int Operator;
    struct bkash accr;
    printf("\nbKash\n");
    printf("1.Robi\n2.Airtel\n3.Banglalink\n4.Grameenphone\n5.Teletalk\n");
    printf("Select Operator: ");
    scanf("%d",&Operator);
    if(Operator >= 1 && Operator <= 5)
    {
        printf("Enter your Number: ");
        scanf("%d", &acc_no);
        printf("Enter the recharge amount: ");
        scanf("%f", &amount);
        while (fread(&accr, sizeof(accr), 1, file))
        {
            if (accr.phone_number == acc_no)
            {
                if (accr.balance >= amount)
                {
                    accr.balance -= amount;
                    fseek(file, -sizeof(accr), SEEK_CUR);
                    fwrite(&accr, sizeof(accr), 1, file);
                    printf("\nYour mobile recharge BDT.%.2f to number 0%d is Successful.\nNew Balance is BDT.%.2f",amount,acc_no,accr.balance);
                }
                else
                {
                    printf("Insufficient balance!");
                }
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("Mobile recharge is not successful. Phone number 0%d doesn't matched...",acc_no);

    }
    else
    {
        printf("The entered menu number is incorrect.\n");
    }
}
void payment()
{
    FILE *file = fopen(BKASH, "rb+");
    if(file == NULL)
    {
        printf("\nUnable to open account file!");
        return;
    }

    int acc_no;
    float amount;
    int ref;
    struct bkash accr;
    printf("Enter your Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter the merchant number: ");
    scanf("%d", &ref);
    printf("Enter the payment amount: ");
    scanf("%f", &amount);
    while (fread(&accr, sizeof(accr), 1, file))
    {
        if (accr.phone_number == acc_no)
        {
            if (accr.balance >= amount)
            {
                accr.balance -= amount;
                fseek(file, -sizeof(accr), SEEK_CUR);
                fwrite(&accr, sizeof(accr), 1, file);
                printf("\nYour payment BDT.%.2f to merchant account %d is Successful.\nNew Balance is BDT.%.2f",amount,ref,accr.balance);
            }
            else
            {
                printf("Insufficient balance!");
            }
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Payment is not successful. Phone number 0%d doesn't matched...",acc_no);


}
void cash_in()
{
    FILE *file = fopen(BKASH, "rb+");
    if(file == NULL)
    {
        printf("Unable to open account file!");
        return;
    }

    int acc_no;
    float amount;
    struct bkash accr;
    printf("Enter your Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter the amount to cash in: ");
    scanf("%f", &amount);

    while (fread(&accr, sizeof(accr), 1, file))
    {
        if (accr.phone_number == acc_no)
        {
            accr.balance += amount;
            fseek(file, -sizeof(accr), SEEK_CUR);
            fwrite(&accr, sizeof(accr), 1, file);
            fclose(file);
            printf("Your Cash in BDT.%.2f is Successful.\nNew Balance is BDT.%.2f",amount,accr.balance);
            return;
        }
    }
    fclose(file);
    printf("Cash in is not successful. Phone number 0%d doesn't matched...",acc_no);

}
void pay_bill()
{
    FILE *file = fopen(BKASH, "rb+");
    if(file == NULL)
    {
        printf("\nUnable to open account file!");
        return;
    }
    int acc_no;
    float amount;
    int refno;
    struct bkash accr;
    printf("Enter your Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter the pay bill amount: ");
    scanf("%f", &amount);
    printf("Enter the bill reference number: ");
    scanf("%d", &refno);
    while (fread(&accr, sizeof(accr), 1, file))
    {
        if (accr.phone_number == acc_no)
        {
            if (accr.balance >= amount)
            {
                accr.balance -= amount;
                fseek(file, -sizeof(accr), SEEK_CUR);
                fwrite(&accr, sizeof(accr), 1, file);
                printf("\nYour pay bill BDT.%.2f to ref.%d is Successful.\nNew Balance is BDT.%.2f",amount,refno,accr.balance);
            }
            else
            {
                printf("Insufficient balance!");
            }
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("Pay bill is not successful. Phone number 0%d doesn't matched...",acc_no);

}
void my_bkash()
{
    FILE *file = fopen(BKASH, "rb");
    if (file == NULL)
    {
        printf("\nUnable to open file!");
        return;
    }
    int accno,choice;
    struct bkash a2;
    printf("\nbKash\n");
    printf("1.Check balance\n2.Request Statement\n3.Update MNP\n4.Change pin\n");
    printf("Select your option:");
    scanf("%d",&choice);
    if(choice > 1 && choice < 5)
    {
        printf("Please call at 16247 for selected service.\n");
    }
    else if(choice == 1)
    {
        printf("Enter your phone number: ");
        scanf("%d",&accno);
        while(fread(&a2,sizeof(a2), 1,file))
        {
            if(a2.phone_number == accno)
            {
                printf("\nYour Account balance is BDT.%.2f",a2.balance);
                fclose(file);
                return;
            }
        }
        fclose(file);
        printf("\nAccount:0%d was not found\n",accno);
    }
    else
    {
        printf("The entered menu number is incorrect.\n");
    }
}
