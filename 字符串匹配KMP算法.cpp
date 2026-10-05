#include<bits/stdc++.h>
using namespace std;

//递推
int* build_next(string b){
    int n = b.length();
    int* next = new int[n];   // 用 new 分配堆内存
    int prefix_len = 0;
    int i = 1;
    next[0] = 0;    //首位赋为0          
    while(i < n){
        if(b[prefix_len] == b[i]){  //把新的字符，和最长相同前缀的后一位进行比较，看看要不要更新最长前缀长度
            prefix_len++;
            next[i] = prefix_len;
            i++;
        }
        
        else{
            if (prefix_len == 0){	//后缀新一位错配了，如果现在最长的前后缀是0，那就把现在next记为0
                next[i] = 0;
                i++;
            }
            else{
                prefix_len = next[prefix_len - 1]; //更新新len为前一位prefix_len
            }
        }
    }
    int* nextval = new int[n];//优化 
    nextval[0] = 0;
    for(int i = 1;i < n;i++){
		int k = next[i];
		if(k > 0&& b[i] == b[k]){
			nextval[i] = nextval[k-1];
		}else{
			nextval[i] = k;
		}
		
	}
    return nextval;//优化 
    
}
/*
                    abcdabcea
经过上面函数，next: 000012301(算上要标数字这个字母的前面一串字符，最前缀和最后缀有几个匹配的) 
prefix_len是next数组的i的情况 
           ABCBABCD
next:      00001234
prefix_len 00001234
		   ABCABCAB
next:	   00012345
prefix_len:
		   AAABABAAB
next:	   012010120
prefix_len:
*/ 
int KMP(string a, string b){
    int length_b = b.length();
    //if (length_b == 0) return 0;          
    int* next = build_next(b);            
    int i = 0;
    int j = 0;
    while(i < (int)a.length()){
        if(a[i] == b[j]){
            i++; j++;	//未错配，子串母串同步向后
        }
        else if (j > 0 && a[i] != b[j]){
            j = next[j-1];	//非第一位失配，用next[j-1]的数值挪子串指针
        }
        else{
            i++;	//第一位失配，主串走一位
        }
        if(j == length_b){	//成功配对，返回头的位置
            int pos = i - j;
            delete[] next;                
            return pos;
        }
    }
    delete[] next;                        
    return -1;                            
}
/*
      abcdabcea,要匹配abce 
next: 000012301
      abce
      从d开始不匹配，c(为d-1)上面是0，把子串第一个a挪到e这里之后再往后0位 
         abce
      第一位就不匹配，往后挪直到第一位匹配
	      abce匹配成功 
*/ 

int main(){
    string a,b;
    cin>>a>>b;
    cout << KMP(a,b);
    return 0;
}
