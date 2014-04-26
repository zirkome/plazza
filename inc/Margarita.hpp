#ifndef _MARGARITA_H_
# define _MARGARITA_H_

# include "APizza.hpp"

class Margarita : public APizza
{
private:
  std::vector<APizza::Ingredients> _ingredients;

public:
  Margarita(APizza::TaillePizza size);
  virtual ~Margarita();

public:
  virtual const std::vector<APizza::Ingredients>& getIngredients() const;
};

#endif /* _MARGARITA_H_ */
