

inline const helpers::Point& GameObject::getPosition() const
{
	return position_;
}


inline const wchar_t& GameObject::getGraficsPresent()const
{
	return graficsPresent_;
}


inline const unsigned int& GameObject::getHealth()const
{
	return health_;
}


inline void GameObject::decreaseHealth()
{
	if (health_ > 0)
		--health_;
}