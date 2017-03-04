class Armor
{
	private:
		int defence;
		int speed_penalty;
	public:
		Armor(int defence, int speed_penalty)
		{
			this->defence = defence;
			this->speed_penalty = speed_penalty;
		}
		virtual ~Armor()
		{
		}

		int get_defence()
		{
			return this->defence;
		}
		int get_speed_penalty()
		{
			return this->speed_penalty;
		}
};

class Chain: public Armor
{
	public:
		Chain(int defence, int speed_penalty):
			Armor(defence, speed_penalty)
		{
		}
};

class Default: public Armor
{
	public:
		Default(int defence, int speed_penalty):
			Armor(defence, speed_penalty)
		{
		}
};
