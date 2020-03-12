#include <bits/stdc++.h>
#include <fstream>
#include <bitset>
using namespace std;
string arr1[10000];
string arr2[10000];
string arr3[10000];
string address[10000];
string Obcode[100000];
 int stcnt=0;
pair<string,string>p[1000]; //symbol table pair
int Hex2Dec(string s){
    int x;
    stringstream ss;
    ss<<s;
    ss>>hex>>x;
    return x;
}
string Dec2Hex(int x){
    stringstream ss;
    ss<<hex<<x;
    return ss.str();

}
string Dec22Hex(int x){
    stringstream ss;
    ss<<hex<<x;
    return ss.str();

}

string obcode(string s){
    if(s=="STL")return "14";
    else if(s=="JSUB")return "48";
    else if(s=="LDA")return "00";
    else if(s=="COMP")return "28";
    else if(s=="JEQ")return "30";
    else if(s=="JSUB")return "48";
    else if(s=="J")return "3C";
    else if(s=="STA")return "0C";
    else if(s=="LDL")return "08";
    else if(s=="RSUB")return "4C";
    else if(s=="LDX")return "04";
    else if(s=="TD")return "E0";
    else if(s=="RD")return "D8";
    else if(s=="STCH")return "54";
    else if(s=="TIX")return "2C";
    else if(s=="WD")return "DC";
    else if(s=="STX")return "10";
    else if(s=="JLT")return "38";
    else if(s=="LDT")return "74";
    else if(s=="LDCH")return "50";
    else if(s=="STCH")return "54";
    else if(s=="TIXR")return "B8";
    else if(s=="JLT")return "38";
    else if(s=="LDB")return "68";
}
    string alpha(char s){
        if(s=='A')return "41";
        else if(s=='B')return "42";
        else if(s=='C')return "43";
        else if(s=='D')return "44";
        else if(s=='E')return "45";
        else if(s=='F')return "46";
        else if(s=='G')return "47";
        else if(s=='H')return "48";
        else if(s=='I')return "49";
        else if(s=='J')return "50";
        else if(s=='K')return "51";
        else if(s=='L')return "52";
        else if(s=='M')return "53";
        else if(s=='N')return "54";
        else if(s=='O')return "55";
        else if(s=='P')return "56";
        else if(s=='Q')return "57";
        else if(s=='R')return "58";
        else if(s=='S')return "59";
        else if(s=='T')return "60";
        else if(s=='U')return "61";
        else if(s=='V')return "62";
        else if(s=='W')return "63";
        else if(s=='Y')return "64";
        else if(s=='Z')return "65"; 
    }

bool isFormat2(string s){
    return s=="CLEAR" || s=="TIXR";
}
bool isFormat1(string s){
    return s=="\\"; ///let's check it out..
}
string HexToBin(string hexdec) 
{ 
    long int i = 0; 
    string v="";
    while (hexdec[i]) { 
        //cout<<"Test"<<v<<endl;
        switch (hexdec[i]) { 
        case '0': 
            v+="0000"; 
            break;
        case '1': 
            v+="0001"; 
            break;
        case '2': 
            v+="0010"; 
            break;
        case '3': 
            v+="0011"; 
            break;
        case '4': 
            v+= "0100"; 
            break;
        case '5': 
            v+="0101"; 
            break;
        case '6': 
            v+="0110"; 
            break;
        case '7': 
            v+="0111"; 
            break;
        case '8': 
            v+="1000"; 
            break;
        case '9': 
            v+="1001"; 
            break;
        case 'A': 
        case 'a': 
            v+="1010"; 
            
        case 'B': 
        case 'b': 
            v+="1011"; 
            break;
        case 'C': 
        case 'c': 
            v+="1100"; 
            break;
        case 'D': 
        case 'd': 
            v+="1101"; 
            break;
        case 'E': 
        case 'e': 
            v+="1110";  
            break;
        case 'F': 
        case 'f': 
            v+="1111"; 
            break;
        } 
        i++; 
    } 
    
    return v;
} 
  
char getHexCharacter(std::string str)
{
	if(str.compare("1111") == 0) return 'F';
	else if(str.compare("1110") == 0) return 'E';
	else if(str.compare("1101")== 0) return 'D';
	else if(str.compare("1100")== 0) return 'C';
	else if(str.compare("1011")== 0) return 'B';
	else if(str.compare("1010")== 0) return 'A';
	else if(str.compare("1001")== 0) return '9';
	else if(str.compare("1000")== 0) return '8';
	else if(str.compare("0111")== 0) return '7';
	else if(str.compare("0110")== 0) return '6';
	else if(str.compare("0101")== 0) return '5';
	else if(str.compare("0100")== 0) return '4';
	else if(str.compare("0011")== 0) return '3';
	else if(str.compare("0010")== 0) return '2';
	else if(str.compare("0001")== 0) return '1';
	else if(str.compare("0000")== 0) return '0';
	else if(str.compare("111")== 0) return '7';
	else if(str.compare("110")== 0) return '6';
	else if(str.compare("101")== 0) return '5';
	else if(str.compare("100")== 0) return '4';
	else if(str.compare("011")== 0) return '3';
	else if(str.compare("010")== 0) return '2';
	else if(str.compare("001")== 0) return '1';
	else if(str.compare("000")== 0) return '0';
	else if(str.compare("11")== 0) return '3';
	else if(str.compare("10")== 0) return '2';
	else if(str.compare("01")== 0) return '1';
	else if(str.compare("00")== 0) return '0';
	else if(str.compare("1")== 0) return '1';
	else if(str.compare("0")== 0) return '0';
}

string Bin2Hex(string rowresult)
{
	std::string endresult = "";
	for(int i = 0; i < rowresult.length(); i = i+4)
	{
		endresult += getHexCharacter(rowresult.substr(i,4));
	}
	return endresult;
}
  

 
template <class Container>
void split(const std::string& str, Container& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}

void get(int counter){
    int cntr=0;
    for(int i=2;i<counter;++i){

    string yk=obcode(arr1[i]); 
    cout<<"\n\n"<<arr1[i]<<endl; 
    cout<<"i-->"<<i<<endl<<"YK--->"<<yk<<endl;
    //cout<<"fyn? "<<yk<<endl;
    string uk=HexToBin(yk);
    //cout<<"uk -->"<<uk<<endl;
    //cout<<"uk len-->"<<uk.length()<<endl;
    if(arr1[i]=="CLEAR"){
        if(arr2[i].length()==1){
             if(arr2[i]=="x")
              Obcode[cntr]="B410";
             else if(arr2[i]=="A")
              Obcode[cntr]="B400";
              else if(arr2[i]=="S")
               Obcode[cntr]="B440";
        }
    }
    else{
    string s1=uk.erase(5,2);
    cout<<s1<<endl;
    string s2;
    int idx=0;
        for(int j=0;j<stcnt;++j){
            if(arr1[i]==p[j].second){
                s2=p[j].first;
                idx=j;
                break;
            }
        }
    string r=s2;
    cout<<"S2-->"<<s2<<endl;
    s2=HexToBin(s2);
    cout<<"s2>>"<<s2<<endl;
    string x=arr2[i];
    string g;
    cout<<"x-->"<<x<<endl;
    if(x=="T"){
        Obcode[cntr]==arr1[i]+"05";
        continue;
    }
    else if(x.at(0)=='#'){ // n  ///check this out !!
        g+="01";
    }
    else if(x.at(0)=='@'){
        g+="10";
    }
    else{
        g+="11";
    }
    if(x.at(x.length()-2)==','){ // x
        g+="1";
    }
    else{
        g+="0";
    }
    if(arr1[i].at(0)!='+'){ // b
        g+="01";
    }   
    if(arr1[i].at(0)=='+'){ /// e 
        g+="001";
    }
    else{
        g+="0";
    }
    
    //cout<<s1<<" "<<g<<endl;
    s1+=g;
    cout<<s1<<endl;

    s1=Bin2Hex(s1); /// without displacment
    cout<<s1<<endl;
    cout<<"r-->"<<r<<endl;
    string pc=p[i+1].first;
    pc=pc.erase(0,1);
    cout<<"pc-->"<<pc<<endl;
    int PCx=Hex2Dec(pc);
    cout<<"PCx-->"<<PCx<<endl;
    int TA=Hex2Dec(r); ////////
    cout<<"TA-->"<<TA<<endl;
    TA=TA-PCx;
    cout<<"TA-->"<<TA<<endl;
    string dis=s1+Dec2Hex(TA);
    cout<<"Displacment--->"<<dis<<endl;
    
    //cout<<pc<<endl;
    Obcode[cntr]=dis;
    cout<<"Obcode-->"<<Obcode[cntr]<<endl;
    }
    cntr++;
    }
   //="";
}
/*Believe me when i wrote this piece of code only god and i know why i wrote this*/
/*But sadly, i fall asleep, so now only god knows :')*/
string x2,x3;
int main(){
    int cnt=0;
    ifstream f("inSICXE.txt");
    string s;
   string s1,s2,s3;
        int i=0;
    while(getline(f,s)){
           string t;
        stringstream l(s);
        if(isspace(s[0])){
            arr1[i]=";";
            l>>t;
            arr2[i]=t;
            ///check the last element///
            if(isspace(s.length()-1)){
                l>>t;
                arr3[i]=t;
            }
        }
        else{
            l>>t;
            arr1[i]=t;
            l>>t;
            arr2[i]=t;
            l>>t;
            arr3[i]=t;
        }

    ++i;
    cnt++;
    }
    for(int i=0;i<cnt;++i){
        if(arr2[i]==arr3[i]){
            arr2[i]=arr1[i];
            arr1[i]=" ";
        }
        cout<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<endl;
    }


    cout<<endl<<endl;



    
       //printing the file
    string start=arr3[0];
    int st=Hex2Dec(start);
    start=Dec2Hex(st);
    
    ///اطبع ياعم الحج
   // cout<<"LOCATION COUNTER\n\n";
    for(int i=0;i<cnt;++i){
        if(i==0){
            address[i]=arr3[0];
            continue;
        }
        if(arr2[i]=="BASE"){
            address[i]=" ";
            cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<endl; 
            continue;
        }
        if(arr2[i]=="LTORG"){
            x2=address[i-1];
            
            address[i]=" ";
            arr1[i]=" ";
            arr3[i]=" ";
            cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<endl; 
            continue;
        }
        
        int v;
        if(arr1[i]=="*" && arr2[i].at(0)=='='){
           string bb=arr3[i];
           v=bb.length()-4;
           //cout<<v<<"\n\n";
           if(arr3[i].at(1)=='X'){
               st+=(v/2);
           }
           else 
            st+=v;   
            address[i]=Dec2Hex(st);
            
            /*string bvs=arr3[i];
            int vs=bvs.length()-4;
            if(arr2[i].at(1)=='C'){
                
                address[i]=x2+vs;
                st=Hex2Dec(address[i]);
            }
            else if(arr2[i].at(1)=='X'){
                address[i]=x2+(vs/2);
                st=Hex2Dec(address[i]);
            }
            cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<endl;*/
            continue;
        }
        
        
        if(arr3[i].at(0)=='='&& (arr3[i].at(1)=='C' || arr3[i].at(1)=='X') ){
            string bb=arr3[i];
           v=bb.length()-4;
           //cout<<v<<"\n\n";
          // cout<<arr3[i].at(1)<<"----\n";
           if(arr3[i].at(1)=='X'){
               cout<<arr3[i].at(1)<<"------\n";
               cout<<"V--->"<<v<<endl;
               st+=(v/2);
           }
           else{
           cout<<arr3[i].at(1)<<"------CCCC\n";
               cout<<"CCC--->"<<v<<endl;
            st+=v;
            
        }
            address[i]=Dec2Hex(st);
            cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<endl;
            continue;
        }


        address[i]=Dec2Hex(st);
        if(arr2[i]=="CLEAR"){
            st+=2;
        }        
        
        if(arr2[i].at(0)=='+') //format 4
            st+=4;
        else if(isFormat2(arr1[i])){
            st+=2;
        }
        else if(isFormat1(arr1[i])){
            st+=1;
        }
        else{ //format 3.
            if(arr2[i]=="RESB"){
                address[i]="1036";
                st+=Hex2Dec("1036");
                continue;
            stringstream bs(arr3[i]);
            int d;
            bs>>d;
            cout<<"value--->"<<arr3[i]<<endl;
            string yarab=Dec2Hex(d);
            stringstream g(yarab);
            g>>d;
            cout<<"------>d "<<d<<endl; // int 
            cout<<"stt--->"<<Dec2Hex(st)<<endl; /// string
            /*stringstream vv(st);
            int v;
            v>>vv;
            cout<<"v-->"<<v<<endl;*/
           // address[i]=d+Dec2Hex(st);
            st+=d;
            cout<<"st--->"<<st<<endl;
            }
            else if(arr2[i]=="RESW"){
                stringstream bs(arr3[i]);
                int d;
                bs>>d;
                string yarab=Dec2Hex(d);
                stringstream g(yarab);
                g>>d;
                st+=(3*d);
            }
            else
            st+=3;
        }
        cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<"\n";
    }
    /*for(int i=0;i<cnt;++i)
        cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<"\n";
     cout<<"\n\nSymbol Table\n\n";
    
    int j=0;
   
    for(int i=0;i<cnt;++i){
        
        if(arr1[i]!=";"){
            cout<<address[i]<<"\t"<<arr1[i]<<endl;
            //mp[j++].insert(address[i],arr1[i]);
            p[j].first=address[i];
            p[j++].second=arr1[i];
            stcnt++;
        }
    }   
    get(cnt);
    cout<<"\n\nObjcet code\n\n";
    for(int i=0;i<cnt;++i){
        if(arr2[i]==arr3[i])
        cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t\t"<<Obcode[i]<<endl;
        else
        cout<<address[i]<<"\t"<<arr1[i]<<"\t"<<arr2[i]<<"\t"<<arr3[i]<<"\t"<<Obcode[i]<<endl;
    }
    cout<<"\n\nHTE Record\n"<<endl;
    int ad1=Hex2Dec(address[0]);
    int ad2=Hex2Dec(address[cnt-1]);
    ad1=ad2-ad1;
    string v=Dec2Hex(ad1);
    string g="";
    int l=v.length();
    if(l<6){
        while(l<6)
            g+="0",l++;
    }
    g+=v;
    cout<<arr1[0]<<"^\t"<<arr3[0]<<"^\t^"<<g;
    cout<<"\nT^\t";
    int m=0;
    while(arr2[m]!="RESW"||arr2[m]!="RESB"){
        cout<<Obcode[m]<<"\t";
        ++m;
    }
    cout<<Dec2Hex(m);
    cout<<"\nE^"<<arr3[0]<<endl;*/
return 0;
}