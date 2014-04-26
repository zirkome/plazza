#ifndef _FANTASIA_H_
# define _FANTASIA_H_

# include "APizza.hpp"

class Fantasia : public APizza
{
private:
  std::vector<APizza::Ingredients> _ingredients;

public:
  Fantasia(APizza::TaillePizza size);
  virtual ~Fantasia();

public:
  virtual const std::vector<APizza::Ingredients>& getIngredients() const;
};

#endif /* _FANTASIA_H_ */
