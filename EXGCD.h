/*
    | Extended Euclidean Algorithm |
    Desc: Find a way to represent GCD in terms of  a  and  b  for which a*x + b*y = gcd(a,b)
    Source: KawakiMeido
    State: Untested lmao
*/

pll extend_euclid(ll a, ll b) {
	if (b == 0) { return {1, 0}; }
	pll p = extend_euclid(b, a % b);
	return {p.se, p.fi - a / b * p.se};
}
