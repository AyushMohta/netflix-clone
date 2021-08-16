#include<iostream.h>
#include<conio.h>

void create(int a[],int n) {
    int i;
    cout<<"\nenter elements of an array:\n";
    for(i=0;i<n;i++)
        cin>>a[i];
}

void traverse(int a[],int n) {
    int i;
    cout<<"\nelements of an array:\n";
    for(i=0;i<n;i++)
        cout<<"\n"<<a[i];
}

int insert(int a[],int n)
{
    int i,pos,ele,temp;
    temp=n;
    cout<<"\nelement to be insert:";
    cin>>ele;
    cout<<"\nenter position:";
    cin>>pos;
    for(i=temp-1;i>=pos;i--)
        a[i+1]=a[i];

    a[pos]=ele;
    n=n+1;
    traverse(a,n);
    return n;
}

int deletes(int a[],int n)
{
    int i,pos,temp;
    temp=n;
    cout<<"\nenter position for deletion:";
    cin>>pos;
    for(i=pos;i<temp-1;i++)
    {
    a[i]=a[i+1];
    }
    n=n-1;
    traverse(a,n);
    return n;
}

void main()
{
    int ch,a[10],b[4],n;
    clrscr();
    cout<<"\nenter the size of array:";
    cin>>n;
    do
    {
    cout<<"\n0:exit";
    cout<<"\n1:create 1st array";
    cout<<"\n2:traverse";
    cout<<"\n3:insert";
    cout<<"\n4:delete";
    cout<<"\nenter your choice:";
    cin>>ch;
    switch(ch)
    {
    case 0:
    break;
    case 1:
    create(a,n);
    break;
    case 2:
    traverse(a,n);
    break;
    case 3:
    n=insert(a,n);
    break;
    case 4:
    n=deletes(a,n);
    break;
    default:
    cout<<"\nwrong choice:";
    }
    }
    while(ch!=0);
    getch();
}