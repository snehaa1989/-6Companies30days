class Solution {
public:
    Solution(double radius, double x_center, double y_center) : 
    m_x_center(x_center), m_y_center(y_center), m_radius(radius) {}
    
    vector<double> randPoint() {
        double x, y;
        while (!isInCircle(x, y)) {
            x = (double)rand()/RAND_MAX * (m_radius + m_radius) + m_x_center - m_radius;
            y = (double)rand()/RAND_MAX * (m_radius + m_radius) + m_y_center - m_radius;
        }
        return {x, y};
    }
    
    bool isInCircle(double x, double y) { 
        return ((x - m_x_center) * (x - m_x_center) + 
            (y - m_y_center) * (y - m_y_center) <= m_radius * m_radius);
    } 
    
private:
    double m_x_center;
    double m_y_center;
    double m_radius;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */