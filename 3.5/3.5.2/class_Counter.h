#pragma once

class Counter
{
public:
	Counter();
	Counter(int count);
	void inc();
	void dec();
	void get_count();

private:
	int count;
};