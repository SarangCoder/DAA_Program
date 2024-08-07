#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int v;
    int w;
    float p;
} Item;


// for taking user inputs 
void input(Item items[], int sizeOfItems){
    
    cout<<"Enter Total" << sizeOfItems << " item's values and Weight"<<endl;
    for(int i=0; i< sizeOfItems; i++){
        cout<<"Enter " << i+1 << " V " ;
        cin>> items[i].v;
        cout<<"Enter " << i+1 << " W " ;
        cin>> items[i].w;
    }
}

//For display user input 

void display(Item items[] , int sizeOfItems){
    int i;
    cout<<" Values: \n ";
    for(i = 0; i< sizeOfItems; i++){
        cout<< items[i].v << " \t";
    }
    cout<<endl;
    for(i=0; i<sizeOfItems; i++){
        cout<< items[i].w << " \t";
    }

    cout<<endl;
}

//for compring the p
bool compare(Item i1 , Item i2){
    return (i1.p > i2.p);
}

// main logic of knapsack

float knapsack(Item items[], int sizeOfItems , int W){
    int i, j;
    float totalValue = 0, totalWeight = 0;

    for(i=0; i<sizeOfItems; i++){
        items[i].p = (float)items[i].v / items[i].w;
    }
    sort(items , items+sizeOfItems , compare);

    for(i=0; i<sizeOfItems; i++){
        if(totalWeight + items[i].w <= W){
            totalValue += items[i].v;
            totalWeight += items[i].w;
        }else{
            int wt = W-totalWeight;
            totalValue += (wt * items[i].p);
            totalWeight +=wt;
            break;
        }
    }

    cout<< "Total Weight in bag " << totalWeight <<endl;
    return totalValue;
}

int main(){
    int W;
    int sizeOfItems;
    cout<<"Enter How many item you want";
    cin>>sizeOfItems;
    Item items[sizeOfItems];
    input(items , sizeOfItems);
    cout<<"Enter the data \n";
    display(items, sizeOfItems);
    cout<<"Enter Knapsack wight \n";
    cin>>W;
    float mxVal = knapsack(items , sizeOfItems, W);
    cout<<"Max Value for " << W << "Weight is " << mxVal;

}