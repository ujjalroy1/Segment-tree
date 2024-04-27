#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class type1>
#define ll long long int
#define endl "\n"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ordered_multiset = tree<type1, null_type, less_equal<type1>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_multiset <ll> kek;(declaration for multiorder set)
// ordered_set o_set;(declaration)
// kek.order_of_key(i);(strictly less then i for multi order set)
// o_set.order_of_key(5) ;(strictly less then i for multi order set)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod 1000000007
ll POW(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}
class segTree
{
    vector<ll> seg;

public:
    segTree(ll n)
    {
        seg.resize(4 * n + 1);
    }
    void build(ll indx, ll low, ll high, ll arr[])
    {
        if (low == high)
        {
            seg[indx] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * indx + 1, low, mid, arr);
        build(2 * indx + 2, mid + 1, high, arr);
        seg[indx] = min(seg[2 * indx + 1], seg[2 * indx + 2]);
    }
    ll query(ll indx,ll low,ll high,ll l,ll r)
{
     if(low>r||high<l)return (ll)(1e17);
     if(low>=l&&high<=r)
     {
         return seg[indx];
     }
     ll mid=(low+high)/2;
     return min(query(2*indx+1,low,mid,l,r),query(2*indx+2,mid+1,high,l,r));

}
void update(ll indx,ll low,ll high,ll ind,ll val)
{
      if(low==high)
      {
          seg[indx]=val;
          return ;
      }
      ll mid=(low+high)/2;
      if(ind<=mid)
      {
          update(2*indx+1,low,mid,ind,val);
      }
      else
      {
          update(2*indx+2,mid+1,high,ind,val);
      }
      seg[indx]=min(seg[2*indx+1],seg[2*indx+2]);
}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
       
        ll n1,n2,i;
        cin>>n1;
        ll arr[n1];
        for(i=0;i<n1;i++)cin>>arr[i];
        cin>>n2;
        ll brr[n2];
        for(i=0;i<n2;i++)
        {
             cin>>brr[i];
        }
         segTree s1(n1),s2(n2);
         s1.build(0,0,n1-1,arr);
         s2.build(0,0,n2-1,brr);
        ll q;
        cin>>q;
        while(q--)
        {
             ll type;
             cin>>type;
             if(type==1)
             {
                  ll l1,r1,l2,r2;
                  cin>>l1>>r1>>l2>>r2;
                  cout<<min(s1.query(0,0,n1-1,l1,r1),s2.query(0,0,n1-1,l1,r1))<<endl;
                 
             }
             else
             {
                ll num;
                cin>>num;
                if(num==1)
                {
                      ll val,indx;
                      cin>>indx>>val;
                      arr[indx]=val;
                      s1.update(0,0,n1-1,indx,val);
                }
                else
                {
                         ll val,indx;
                      cin>>indx>>val;
                      brr[indx]=val;
                      s2.update(0,0,n1-1,indx,val);
                }

             }
        }


    }

    return 0;
}
