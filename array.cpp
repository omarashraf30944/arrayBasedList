#include<iostream>
using namespace std;

class arraylist{
    int*arr;
    int maxsize;
    int length;
public:
    arraylist(int s){
        if (s < 0)
            maxsize = 10;
        else
            maxsize = s;
        length = 0;
        arr = new int[maxsize];
    }
    bool isEmpty(){
        return length == 0;
    }
    
    bool isFull(){
        return length == maxsize;
    }
    
    int getSize(){
        return length;
    }
    
    void print(){
        cout<<" [ "; 
        for(int i = 0; i < length; i++){
            cout<< arr[i]<<" ";
        }cout<<" ] ";
    }
    void removeatpos(int pos, int Element){
        if(isEmpty())
            cout<<"the array is empty "<<endl;
        else if (pos < 0 || pos > length)
            cout<<"out of range "<<endl;
        else 
            for(size_t i = length; i > pos; i++){
                arr[i] = arr [i + 1];
            }
            arr[pos] = Element;
            length--;
    }
    void insertatpos(int pos, int element){
        if(isEmpty())
            cout<<"the array is empty "<<endl;
        else if (pos < 0 || pos > length)
            cout<<"out of range "<<endl;
        else 
            for(size_t i = pos; i < length; i++){
                arr[i] = arr [i - 1];
            }
            arr[pos]=element;
            length++;
    }
    
    void insertatend(int element){
        if(isFull()){
            cout<<"array is full "<<endl;
        }else{
            arr[length] = element;
        }length++;
    }
    
    int search (int element){
        for(size_t i= 0; i < length; i++){
            if(arr[i] == element){
            return i;}
            
        }return -1;
    }
    
    void insertnoduplicate(int element){
        if(search(element) ==-1){
            insertatend(element);
        }else{
            cout<<"element is there"<<endl;
        }
    }
    
    void updateat(int pos, int element){
        if(pos < 0 || pos > length){
            cout<<"out of range "<<endl;
        }else{
            arr[pos] = element;
        }
    }
    
    
    int getElementAtpos(int pos){
        if (pos < 0 || pos > length)
        return arr[pos];
    }
    
    
    ~arraylist(){
        delete  []  arr;
    }
};

int main(){

arraylist ar(100);
cout<<ar.getSize()<<endl;
ar.insertatpos(0,10);    
ar.insertatpos(1,20);
ar.insertatend(30);
ar.insertnoduplicate(40); 
ar.print();
cout<<endl<<ar.getSize()<<endl;
ar.print();
    return 0;
}