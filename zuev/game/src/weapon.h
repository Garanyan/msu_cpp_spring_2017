class Weapon
{
	private:
		int speed;
		int distance;
		int attack;
	public:
		Weapon(int speed, int distance, int attack)
		{
			this->speed    = speed;
			this->distance = distance;
			this->attack   = attack;
		}
		virtual ~Weapon()
		{
		}

		int get_speed()
		{
			return this->speed;
		}
		int get_distance()
		{
			return this->distance;
		}
		int get_attack()
		{
			return this->attack;
		}
};

class Shovel: public Weapon
{
	public:
		Shovel(int speed, int distance, int attack):
			Weapon(speed, distance, attack)
		{
		}
};

class Sword: public Weapon
{
	public:
		Sword(int speed, int distance, int attack):
			Weapon(speed, distance, attack)
		{
		}
};

class Bow: public Weapon
{
	public:
		Bow(int speed, int distance, int attack):
			Weapon(speed, distance, attack)
		{
		}
};

class Hammer: public Weapon
{
	public:
		Hammer(int speed, int distance, int attack):
			Weapon(speed, distance, attack)
		{
		}
};
