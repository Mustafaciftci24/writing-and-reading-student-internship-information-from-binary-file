#include <stdio.h>
#include <stdlib.h>
#define ArraySize 80
 struct DATE {
    int mm,dd,yy;
};
struct Students{
    int
    studentNumber,
    totalWorkDaysInCompany;
    char
    studentsNameAndSurname[ArraySize],
    studentsCellphoneNumber[ArraySize],
    studentsEmail[ArraySize],
    studentsHomeAddress[ArraySize],
    studentsCity[ArraySize],
    companyName[ArraySize],
    companyAddress[ArraySize],
    companyLocation_city_district_[ArraySize],
    companyPhoneNumber[ArraySize],
    companyEmail[ArraySize];

    struct DATE
    beginningDateOfInternship,
    endingDateOfInternship;
};
struct Students getStudentInfo(struct Students student1);

void writeToFile(struct Students student1);

void readFromFile(struct Students output);

int main() {
    struct Students student1;
    struct Students output;

    student1 = getStudentInfo(student1);
    writeToFile(student1);
    readFromFile(output);
    return 0;
}
struct Students getStudentInfo(struct Students student1 ){

    printf("Enter student's number\n");
    scanf("%d",&student1.studentNumber);
    getchar();

    printf("Enter student's name and surname\n");
    fgets(student1.studentsNameAndSurname,ArraySize,stdin);

    printf("Enter student's phone number\n");
    fgets(student1.studentsCellphoneNumber,ArraySize,stdin);

    printf("Enter student's e-mail \n");
    fgets(student1.studentsEmail,ArraySize,stdin);

    printf("Enter student's home address \n");
    fgets(student1.studentsHomeAddress,ArraySize,stdin);

    printf("Enter student's city\n");
    fgets(student1.studentsCity,ArraySize,stdin);

    printf("Enter company's name\n");
    fgets(student1.companyName,ArraySize,stdin);

    printf("Enter company's address \n");
    fgets(student1.companyAddress,ArraySize,stdin);

    printf("Enter company's location city\\district\n");
    fgets(student1.companyLocation_city_district_,ArraySize,stdin);

    printf("Enter company's phone number\n");
    fgets(student1.companyPhoneNumber,ArraySize,stdin);

    printf("Enter company's e-mail\n");
    fgets(student1.companyEmail,ArraySize,stdin);

    printf("Enter student's work days in company\n");
    scanf("%d",&student1.totalWorkDaysInCompany);

    printf("Enter beginning day of internship in mm dd yy format\n");
    scanf("%d%d%d",
          &student1.beginningDateOfInternship.mm,
          &student1.beginningDateOfInternship.dd,
          &student1.beginningDateOfInternship.yy);
    printf("Enter ending day of internship mm dd yy format\n");
    scanf("%d%d%d",
          &student1.endingDateOfInternship.mm,
          &student1.endingDateOfInternship.dd,
          &student1.endingDateOfInternship.yy);

    return student1;
}
void writeToFile(struct Students student1){
    FILE *file_pointer;
    file_pointer = fopen("student.bin","wb");

    if (file_pointer == NULL){
        printf("Error while opening the file");
        exit(1);
    }

    fwrite(&student1,sizeof (struct Students),1,file_pointer);
    fclose(file_pointer);
}
void readFromFile(struct Students output){
    FILE *file_pointer;
    file_pointer = fopen("student.bin","rb");
    if(file_pointer == NULL){
        printf("Error while opening the file");
        exit(1);
    }

    while((fread(&output,sizeof (struct Students),1,file_pointer))){

        printf("Student's number is: %d\n",output.studentNumber);
        printf("Student's name and surname is: %s",output.studentsNameAndSurname);
        printf("Student's phone number is: %s",output.studentsCellphoneNumber);
        printf("Student's e-mail is: %s",output.studentsEmail);
        printf("Student's home address is: %s",output.studentsHomeAddress);
        printf("The city where student live is: %s",output.studentsCity);
        printf("Company name is: %s",output.companyName);
        printf("Company address is: %s",output.companyAddress);
        printf("Company location is: %s",output.companyLocation_city_district_);
        printf("Company phone number is: %s",output.companyPhoneNumber);
        printf("Company e-mail is: %s",output.companyEmail);
        printf("Total work day in company is: %d\n",output.totalWorkDaysInCompany);
        printf("Beginning day of internship is: %d/%d/%d\n",
               output.beginningDateOfInternship.mm,
               output.beginningDateOfInternship.dd,
               output.beginningDateOfInternship.yy);
        printf("Ending day of internship is: %d/%d/%d\n",
               output.endingDateOfInternship.mm,
               output.endingDateOfInternship.dd,
               output.endingDateOfInternship.yy);
    }
    fclose(file_pointer);
}
