




namespace Math
{
	template<class T>
	T max(T left, T right)
	{
		return left > right ? left : right;
	}

	template<class T>
	T min(T left, T right)
	{
		return left < right ? left : right;
	}
}