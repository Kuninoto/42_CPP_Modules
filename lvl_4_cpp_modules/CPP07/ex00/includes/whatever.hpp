#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& parameter1, T& parameter2)
{
	T temp;

	temp = parameter1;
	parameter1 = parameter2;
	parameter2 = temp;
}

template <typename T>
T min(T parameter1, T parameter2)
{
	if (parameter1 == parameter2)
		return parameter2;
	return parameter1 > parameter2 ? parameter2 : parameter1;
}

template <typename T>
T max(T parameter1, T parameter2)
{
	if (parameter1 == parameter2)
		return parameter2;
	return parameter1 > parameter2 ? parameter1 : parameter2;
}

#endif // WHATEVER_HPP