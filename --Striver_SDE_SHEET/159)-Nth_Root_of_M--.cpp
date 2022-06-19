double findNthRootOfM(int n, long long m) {

 
    double error = 1e-7;
    double diff = 1e18;
    double xk = 2;
    while (diff > error) {
        double xk_1 = (pow(xk, n) * (n - 1) + m) / (n * pow(xk, n - 1));
        diff = abs(xk - xk_1);
        xk = xk_1;
    }
 
    return xk;
}