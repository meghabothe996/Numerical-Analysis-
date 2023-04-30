
class rootfinding{
    private: 
        float a,b,allowed_error,mid_point;
    public:
        rootfinding();
        //newton raphson
        void newtonRaphson_read();
        float ne_function(const float x);
	    float ne_dfunction(const float x);
        int newtonRaphson_method();    
        //bisection
        void bisection_read();
        int bisection_method();
        float bi_function(const float x);
        //fixed point  
        void fixedpoint_read();
	    float fix_function(const float x);
	    int fixedpoint_method();


};
