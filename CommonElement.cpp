class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> re;
            map<int,int> mp;
            for(int i=0;i<n1;i++)mp[A[i]]=1;
            for(int i=0;i<n2;i++)if(mp[B[i]]==1)mp[B[i]]=2;
            for(int i=0;i<n3;i++){
                if(mp[C[i]]==2){
                    re.push_back(C[i]);
                    mp[C[i]]=-1;
                }
            }
            return re;
        }

};
