#ifndef _AMERICANA_H_
# define _AMERICANA_H_

# include "APizza.hpp"

class Americana : public APizza
{
private:
  std::vector<APizza::Ingredients> _ingredients;

public:
  Americana(APizza::TaillePizza size);
  virtual ~Americana();

public:
  virtual const std::vector<APizza::Ingredients>& getIngredients() const;
};

#endif /* _AMERICANA_H_ */
