// WAP to read basic salary then find tax and allowance, tax is 20% of basic salary and allowance is 40% of basic salary. Also find out net salary.

#include<stdio.h>

int main(){
    float basic_salary,tax,allowance,gross_salary,net_salary;
    printf("Enter basic_salary: ");
    scanf("%f",&basic_salary);
    tax=0.2*basic_salary;
    allowance=0.4*basic_salary;
    gross_salary=basic_salary+allowance;
    net_salary=gross_salary-tax;
    printf("Tax=%g\nAllowance=%g\nGross Salary=%g\nNet Salary=%g\n",tax,allowance,gross_salary,net_salary);
    return 0;
}
