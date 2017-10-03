//
//  main.cpp
//  Problems
//
//  Created by Dinkar Khattar on 8/31/17.
//  Copyright © 2017 Dinkar Khattar. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isUnique(string n)
{
    for (int i = 0; i<n.size(); i++)
    {
        for(int j = 0; j<n.size(); j++)
        {
            if (j==i)
            {
                continue;
            }
            if (n[j]==n[i])
            {
                cout<<"false";
                return false;
            }
        }
    }
    cout<<"true";
    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printMatrix(vector<vector<int>> m, int r, int c)
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<m[i][j];
        }
        cout<<endl;
    }
}

vector<vector<int>> rotate(vector<vector<int>> &m, int s)
{
    vector<vector<int>> n;
    for (int i=0; i<s; i++)
    {
        vector<int> t(s, 0);
        n.push_back(t);
    }
    
    for (int i=0; i<s; i++)
    {
        for (int j=0; j<s; j++)
        {
            n[j][s-i-1]=m[i][j];
        }
    }
    
    return n;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<int>> zeroMatrix(vector<vector<int>> &m, int r, int c)
{
    vector<bool> row(r, false);
    vector<bool> col(c, false);
    
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (m[i][j]==0)
            {
                row[i]=true;
                col[j]=true;
            }
        }
    }
    
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (m[i][j]==0)
            {
                for (int k=0; k<r; k++)
                {
                    m[k][j]=0;
                }
                
                for (int k=0; k<c; k++)
                {
                    m[i][k]=0;
                }
                
                return m;
            }
        }
    }
    
    return m;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Driver program to test above function */
//int main()
//{
//    char X[] = "AGGTAB";
//    char Y[] = "GXTXAYB";
//    
//    int m = strlen(X);
//    int n = strlen(Y);
//    
//    printf("Length of LCS is %d ", lcs( X, Y, m, n ) );
//    
//    return 0;
//}


char makeUpper(char n) {
    return toupper(n);
}

string helper(string& a, string b, int m, int n)
{
    if (n==0 || m==0) {
        return "";
    }
    char fa = makeUpper(a[m-1]);
    char fb =b[n-1];
    if (fa==fb) {
        a[m-1] = toupper(a[m-1]);
        return (fb + helper(a, b, m-1, n-1));
    }
    else
    {
        return (helper(a, b, m-1, n));
    }
}

bool isInb(string b, char c)
{
    for (int i=0; i<b.length(); i++)
    {
        if (b[i]==c)
        {
            return true;
        }
    }
    return false;
}

string abbreviation(string a, string b) {
    map<int, bool> wordMap;
    
//    string lowerAnswer = "";
//    string leftover = "";
//    
//    for (int i=0; i<answer.length(); i++)
//    {
//        lowerAnswer+=tolower(answer[i]);
//    }
    
    if (a.length()<b.length())
    {
        return "NO";
    }
    
    if (a.length()==b.length())
    {
        string au="";
        for (int i=0; i<a.length(); i++)
        {
            au+=toupper(a[i]);
        }
        if (au!=b)
        {
            return "NO";
        }
    }
    
    int n = 0;
    
    bool m1 = true;
    bool m2 = false;
    
    for (int i=0; i<a.length(); i++)
    {
        if (n>b.length())
        {
            break;
        }
        wordMap[i] = false;
        char a1 = b[n];
        char a2 = a[i];
        if (a1==a2)
        {
            n++;
            wordMap[i] = true;
            continue;
        }
    }
    
    for (int i=0; i<a.length(); i++)
    {
        if (isupper(a[i]) && !wordMap[i])
        {
            m1 = false;
        }
    }
    
    string answer = helper(a, b, a.length(), b.length());
    reverse(answer.begin(), answer.end());

    
    if (answer==b)
    {
        m2 = true;
    }
    else
    {
        m2 = false;
    }
    
    if (m1 || m2)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int main() {
//    10
//    RDWPJPAMKGRIWAPBZSYWALDBLDOFLWIQPMPLEMCJXKAENTLVYMSJNRJAQQPWAGVcGOHEWQYZDJRAXZOYDMNZJVUSJGKKKSYNCSFWKVNHOGVYULALKEBUNZHERDDOFCYWBUCJGbvqlddfazmmohcewjg
//    RDPJPAMKGRIWAPBZSYWALDBLOFWIQPMPLEMCJXKAENTLVYMJNRJAQQPWAGVGOHEWQYZDJRAXZOYDMNZJVUSJGKKKSYNCSFWKVNHOGVYULALKEBUNZHERDOFCYWBUCJG
//    MBQEVZPBjcbswirgrmkkfvfvcpiukuxlnxkkenqp
//    MBQEVZP
//    DINVMKSOfsVQByBnCWNKPRFRKMhFRSkNQRBVNTIKNBXRSXdADOSeNDcLWFCERZOLQjEZCEPKXPCYKCVKALNxBADQBFDQUpdqunpelxauyyrwtjpkwoxlrrqbjtxlkvkcajhpqhqeitafcsjxwtttzyhzvh
//    DINVMKSOVQBBCWNKPRFRKMFRSNQRBVNTIKNBXRSXADOSNDLWFCERZOLQEZCEPKXPCYKCVKALNBADQBFDQU
//    BFZZVHdQYHQEMNEFFRFJTQmNWHFVXRXlGTFNBqWQmyOWYWSTDSTMJRYHjBNTEWADLgHVgGIRGKFQSeCXNFNaIFAXOiQORUDROaNoJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMvSTGEQCYAJSFvbqivjuqvuzafvwwifnrlcxgbjmigkms
//    BFZZVHQYHQEMNEFFRFJTQNWHFVXRXGTFNBWQOWYWSTDSTMJRYHBNTEWADLHVGIRGKFQSCXNFNIFAXOQORUDRONJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMSTGEQCYAJSF
//    AQIUQVIPJDKYNEBPXFGVHCMFGvURORPRSTYQYJZCYJDNFRPRYTMZIsNDOJAOAGAEFRCDKUJBhdkedalbwoxxnoyowoxpdlelovibyiwat
//    AQIUQVIPJDKYNEBPXFGVHCMFGURORPRSTYQYJZCYJDNFRPRYTMZINDOJAOAGAEFRCDKUJB
//    HCPXJZTDXLWHYKHPPDFYFDJWTAETQLJCIIPVHMZHHOQTKONUHGYVKLXTFTBEMYAWXTCSwNJYALIGMIBDOWKIVStFATDOZCYSUCaATUWORPMTFPKTNHDSFWKRKBrXNBYICOZYDWLLElKKWTFAUSTZKFDCBQNYVcWKDHDMXJGFORwURHISYLBIZSOJXVRVBNPQLRJKIN
//    HCPXJZTDXLWHYKHPPDFYFDJWTAETQLJCIIPVHMZHHOQTKONUHGYVKLXTFTBEMYAWXTCSNJYALIGMIBDOWKIVSFATDOZCYSUCATUWORPMTFPKTNHDSFWKRKBXNBYICOZYDWLLEKKWTFAUSTZKFDCBQNYVWKDHDMXJGFORURHISYLBIZSOJXVRVBNPQLRJKINIIOYB
//    IZLAKtDFAITDNWMVQPDShQQFGTRIXDLNBQPZRpuRJMLLPHBMOWrNagJDPPREZSYBHIWKDHLkjPSEUWIVQYUfPPJYKCbPEKCSKBRIAAJTMDPAOLNWSQESOTRQZOFTMTTGTDTrWLPENHXHLDWAFNDZMIFlogtcddtulusydquboxquwmgcji
//    IZLAKDFAITDNWMVQPDSQQFGTRIXDLNBQPZRRJMLLPHBMOWNJDPPREZSYBHIWKDHLPSEUWIVQYUPPJYKCPEKCSKBRIAAJTMDPAOLNWSQESOTRQZOFTMTTGTDTWLPENHXHLDWAFNDZMIF
//    KRBPLVCTESRNPTCVNDMPTQYvFAWBGYPQHNXNAESRQMKFDZIEKVNZXSXKCFHQYCMMANPQFHWCEeNGOLWTUXZVMQNDZfRPLUFZcSTRLRYAZUKAZYXCVTNTNScSDFTBJSUKEQKZRDITZUCFVAPLCLTUWAXOnNHPYEOZDGWZPBJQBZEOFAeXTFJDWRHI
//    KRBPVCTESRNPTCVNDMPTQYFWBGYPQHXNAESRQMFDZIEKVNZXSXKFHQYCMMANPQFHWCNGOLWTUXZVMQNDZRPLUFZSTRLRYAZUAZYXCVTNTNSSDTBJSUKEQKZRDITZUCFVAPCLTUWAXONHPYEOZDGWZPBJQBZEOAXTFJDWRHIPGQVCWODYNNV
//    WOAECAAVWMSQMIMYMAPEVARGIZCTIVNLAgydhmrxwcjltpjdewxhxrtynyyuyhqwbpkwuqtpwmyhemjxvwoazumyfstoumreirdkwbmepwbrgmyhjgtqeltzxnwhbunvuoejnhfqcikggaqjgsoqhzrmu
//    WOAECAAVWMSQMIMYMAPEVARGIZCTIVNLA
//    RMPRWOBYTSjXGVJQPDQEHTWXMOGcHVWKATSWLBWPJBQTYKVHKMFKCYVVJXGLUEZTLSXChGBCAOAMiFEAPPAGWeMXXQAQTFCZGXKOGZLLUWTZDOYVWHIJZEIDOSHPwFWHYXCIZKTjKKVKQNDXMTCCBQMAGVCDPZOXHPSEQYthuqclzletakrqbzmaohadpog
//    RMPRWOBYTSXGVJQPDQEHTWXMOGHVWKATSWLBWPJBQTYKVHKMFKCYVVJXGLUEZTLSXCGBCAOAMFEAPPAGWMXXQAQTFCZGXKOGZLLUWTZDOYVWHIJZEIDOSHPFWHYXCIZKTKKVKQNDXMTCCBQMAGVCDPZOXHPSEQY
//    string result = abbreviation("KFxxxXxQxxx", "KFX");
//    cout<<result<<endl;
//    return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
    
    
}
