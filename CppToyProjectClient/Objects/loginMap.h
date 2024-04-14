class LoginMap : public Map
{
public:
	LoginMap();
	virtual ~LoginMap();

protected:
	virtual void loadResources() override;

public:
	virtual void draw() override;
};

