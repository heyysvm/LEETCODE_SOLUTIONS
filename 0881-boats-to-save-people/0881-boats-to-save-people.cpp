class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int l=0;
        int boat = 0 ; 
        int r = people.size()-1;
        sort(people.begin(),people.end());

        while(l<=r){
            if(people[l]+people[r] <= limit ) l++ , r--;
            // else if(people[l]<=limit) boat ++ , l++;
            // else if(people[r]<=limit) boat++ , r--;
            else r--;
            boat++;
        }
        return boat;
    }
};