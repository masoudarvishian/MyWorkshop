#ifndef VIEW_BASE_H
#define VIEW_BASE_H

class ViewBase
{
public:
	virtual ~ViewBase() {}
	virtual void Run() = 0;
};

#endif // !VIEW_BASE_H

