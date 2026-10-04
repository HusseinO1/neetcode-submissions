class Solution {
public:
    int characterReplacement(string s, int k)
{
vector<int> seen(26, 0);

int maxFreq = 0;

int maxSize = 0;

int left = 0;

for(int right = 0; right < (int) s.size(); ++right)
{
seen[s[right] - 'A']++;

maxFreq = max(maxFreq, (seen[s[right] - 'A']));

if(right - left + 1 - maxFreq > k)
{
	seen[s[left] - 'A']--;
	left++;
}

maxSize = max(maxSize, right - left + 1);
}	

return maxSize;
}

};
