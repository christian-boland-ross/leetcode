class Solution
{
public:
    bool isPalindrome(string s)
    {
        size_t front = 0;
        size_t rear = s.size();

        while(front < rear)
        {
            //ignore non-alphanumeric characters
            while(front < rear && !isalnum(s[front]))
                front++;
            while(front < rear && !isalnum(s[rear - 1]))
                rear--;

            //front and rear indices meet or overlap
            if(front >= rear)
                break;

            //normalise case
            if(tolower(s[front]) !=
               tolower(s[rear - 1]))
                return false;

            front++;
            rear--;
        }

        return true;
    }
};