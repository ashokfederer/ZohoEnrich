#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len(char* str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        
    }
    return i;
}


/*void concat(char* str)
{
    int length = len(str);
    int i;
    for(i=0;i<length;i++)
    {
        res[reslen++]=str[i];
    }
}*/

struct contact_persons
{
    char *personid;
    char *firstname;
    char *lastname;
    char *email;
};

struct contact_details
{
    char *id;
    char *name;
    char *street;
    char *area;
    char *city;
    struct contact_persons person[2];
}contact[2];

char* toString(struct contact_details* contact)
{
    char* res;
    res = (char*)malloc(100);
    res[0]='{';
    res[1]='\n';
    strcat(res,"\t\"id\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].id);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"name\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].name);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"street\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].street);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"area\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].area);
    strcat(res,"\"");
    strcat(res,",\n");
    
    strcat(res,"\t\"city\" : ");
    strcat(res,"\"");
    strcat(res,contact[0].city);
    strcat(res,"\"");
    strcat(res,"\n");
    
    strcat(res,"\tcontact_persons : [\n");
    strcat(res,"\t\t{");
    strcat(res,"\t\t\tcontact person id : ");
    strcat(res,contact[0].person[0].id);
    
    
    
    strcat(res,"}");
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char* res;
    res = (char*)malloc(100);
    contact[0].id = "123";
    contact[0].name = "RMK";
    contact[0].street = "RSM Street";
    contact[0].area = "RSM Nagar";
    contact[0].city = "Chennai";
    contact[0].person[0].personid = "1";
    contact[0].person[0].firstname = "Ashok";
    contact[0].person[0].lastname = "Kumar";
    contact[0].person[0].email ="ashok@gmail.com";
    res=toString(contact);
    printf("%s\n",res);
    
    return 0;
}
