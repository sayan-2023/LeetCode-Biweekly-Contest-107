


//join("ab","bc")="abc" // since 'b' is common;


// join ("ab","cd")="cd"


// According  to problem make 

//Make stri = join(stri - 1, words[i])

//Make stri = join(words[i], stri - 1)


// Return min lenghth of finaql string after concatenation 



//Think what will be recursion function in case???

// if common will occure sting lenght reduce by '1'

//At first :
// i start from index '1

// start=v[0[0]

//end=v[0].back()

//end=v[0].back()

// case 1:
//v[i].size()-(v[0].back()==v[i][0])+func(start,v[i].back(),i+1) This is case for when you Make stri = join(stri - 1, words[i])


/// case 2: 
//v[i].size()-(v[0].back()==v[i][0])+func(v[i][0] ,end,i+1) This is case for when you Make stri = join( words[i],stri-1)

#include<bits/stdc++.h>

class Solution {
public:

  int dp[1000] [26] [26];


int dfs(vector<string> &v, int start, int end, int i) 
{
    if(i >= v.size()) 
        return 0;
// start and end are charecters and its intilized 26
//As dp contain index so all the charecters are converted to corrosponding numbers 
    if(dp[i][start] [end] != -1) 
        return dp[i][start][end];

    int ans = INT_MAX;

    ans = min(ans, (int)v[i].size()-(end + 'a' == v[i][0]) + dfs (v, start, v[i].back() -'a', i + 1));

    ans = min(ans, (int)v[i].size()- (start + 'a' == v[i].back()) + dfs(v, v[i][0] -'a', end, i + 1));

    return dp[i][start] [end] = ans;

}

int minimizeConcatenatedLength (vector<string>& v) { 
    
    memset(dp, -1, sizeof(dp)); 
    return v[0].size() + dfs(v, v[0] [0] - 'a', v[0].back()- 'a', 1);
        
    }
};