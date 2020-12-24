#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;
struct node{
    ll  sum;
    ll square;
};
struct lazynode{
    ll set;
    ll update;
};
void buildtree(int*arr,node*tree,int start,int end,int treeindex){
if(start==end){
tree[treeindex].sum=arr[start];
tree[treeindex].square=arr[start]*arr[start];
return;
}
int mid=(start+end)/2;
buildtree(arr,tree,start,mid,2*treeindex);
buildtree(arr,tree,mid+1,end,2*treeindex+1);
tree[treeindex].sum=tree[2*treeindex].sum+tree[2*treeindex+1].sum;
tree[treeindex].square=tree[2*treeindex].square+tree[2*treeindex+1].square;
}
void updatelazy(lazynode* lazy,node*tree,int start,int end,int treeindex,int type,int left,int right,int value)
{
    if(start>end){
        return;
    }
    if(lazy[treeindex].set!=0){
        ll x=lazy[treeindex].set;
        tree[treeindex].sum=x*(end-start+1);
        tree[treeindex].square=x*x*(end-start+1);
        if(start!=end){
            lazy[2*treeindex].set=x;
            lazy[2*treeindex+1].set=x;
            lazy[2*treeindex].update=0;
            lazy[2*treeindex+1].update=0;
        }
        lazy[treeindex].set=0;
    }
    if(lazy[treeindex].update!=0){
        ll x = lazy[treeindex].update;
        tree[treeindex].sum += x * (end - start + 1);
        tree[treeindex].square +=(x * x) * (end - start + 1)+(2*x*(tree[treeindex].sum));
        if (start != end)
        {
            lazy[2 * treeindex].update +=x ;
            lazy[2 * treeindex + 1].update +=x;
        }
        lazy[treeindex].update = 0;
    }
    if(start>right||end<left){
        return;
    }
    if(start>=left&&end<=right){
        if(type==0){
            tree[treeindex].sum=value*(end-start+1);
            tree[treeindex].square=value*value*(end-start+1);
            if (start != end)
            {
                lazy[2 * treeindex].set = value;
                lazy[2 * treeindex + 1].set = value;
	 	 lazy[2*treeindex+1].update=0;
                 lazy[2*treeindex].update=0;
            }
        }else{
            tree[treeindex].sum += value * (right - left + 1);
            tree[treeindex].square += (value * value) * (right - left + 1)+(2*value*tree[treeindex].sum);
            if(start!=end){
                lazy[2 * treeindex].update +=value;
                lazy[2 * treeindex + 1].update +=value;
            }
        }
        return;
    }
    int mid=(start+end)/2;
    updatelazy(lazy,tree,start,mid,2*treeindex,type,left,right,value);
    updatelazy(lazy, tree, mid+1,end, 2 * treeindex+1, type, left, right, value);
    tree[treeindex].sum=tree[2*treeindex].sum+tree[2*treeindex+1].sum;
    tree[treeindex].square=tree[2*treeindex].square+tree[2*treeindex+1].square;
}
ll query(lazynode*lazy,node*tree,int start,int end,int treeindex,int type,int left,int right){
     if(start>end){
 return 0;
}
  if(lazy[treeindex].set!=0){
        ll x=lazy[treeindex].set;
        tree[treeindex].sum=x*(end-start+1);
        tree[treeindex].square=x*x*(end-start+1);
        if(start!=end){
            lazy[2*treeindex].set=x;
            lazy[2*treeindex+1].set=x;
	            lazy[2*treeindex].update=0;
            lazy[2*treeindex+1].update=0;
        }
        lazy[treeindex].set=0;
    }
    if(lazy[treeindex].update!=0){
        ll x = lazy[treeindex].update;
        tree[treeindex].sum += x * (end - start + 1);
        tree[treeindex].square += x * x * (end - start + 1)+2*x*(tree[treeindex].sum);
        if (start != end)
        {
            lazy[2 * treeindex].update +=x ;
            lazy[2 * treeindex + 1].update +=x;
        }
        lazy[treeindex].update = 0;
    }
    if(start>right||end<left){
        return 0;
    }
    if(start>=left&&end<=right){
    return tree[treeindex].square;	
    }
    int mid=(start+end)/2;
    ll ans1=query(lazy,tree,start,mid,2*treeindex,type,left,right);
    ll ans2=query(lazy,tree,mid+1,end,2*treeindex+1,type,left,right);
    return ans1+ans2;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
int l=1;
    while(t--){
        int n,q;
        cin>>n>>q;
        int *arr=new int [n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        node*tree=new node[4*n];
        buildtree(arr,tree,0,n-1,1);
        lazynode*lazy=new lazynode[4*n]();
        int type,left,right,value;
	cout<<"Case "<<l<<":"<<endl;
        for(int i=0;i<q;i++){
            cin>>type;
            if(type==0||type==1){
                cin>>left>>right>>value;
                updatelazy(lazy,tree,0,n-1,1,type,left-1,right-1,value);
            }else{
                cin>>left>>right;
                cout<<query(lazy,tree,0,n-1,1,type,left-1,right-1)<<endl;
            }
        }
    
     l++;
    }

    return 0;
}
