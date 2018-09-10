#include <iostream>
#include <cstring> 
#include <cstdio> 
using namespace std;
int main() {
	int N, M;
	cin >> N;
	cin >> M;
	int pre[N + 1][N + 1];
	memset(pre, 0, sizeof(pre));
	for (int i = 1; i <= N; i++) //初始化           
    pre[i][i]=1;      
    int a1,a2;    
    for(int i=1;i<=M;i++)    
    {        
        cin>>a1;        
        cin>>a2;        
        pre[a1][a2] = 1;    
        }    
        int ans = 0;    
        for(int i=1;i<=N;i++)    
        {          
            bool flag = true;        
            for(int j = 0; j <= N; j++)       
             {                       
                  if(!pre[i][j])            
                  {                
                      flag = false;                
                      break;            
                      }                    
                      }        
                      if(flag)            
                      ans++;            
                      }              
                      cout<<ans<<endl;                   
                      return 0;  
                      }
	