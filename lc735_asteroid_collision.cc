class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> asteroid_stack;
       
        for (int asteroid : asteroids) {
            bool add_asteroid = true;
            while (!asteroid_stack.empty() && asteroid_stack.top() > 0 && asteroid < 0) {
                int top = asteroid_stack.top(); 
                if (top + asteroid > 0) {
                    add_asteroid = false;
                    break; 
                } else if (top + asteroid < 0) {
                    asteroid_stack.pop(); 
                } else {
                    asteroid_stack.pop();
                    add_asteroid = false;
                    break;
                }
            } 
            if (add_asteroid) {
                asteroid_stack.push(asteroid);
            }
        }
        
        std::vector<int> result(asteroid_stack.size());
        for (int i = result.size() - 1; i >= 0; --i) { 
            result[i] = asteroid_stack.top();
            asteroid_stack.pop();
        }
        return result;
    }
};
