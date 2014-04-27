#ifndef _REGINA_H_
# define _REGINA_H_

# include "APizza.hpp"

class Regina : public APizza
{
private:
  std::vector<APizza::Ingredients> _ingredients;

public:
  Regina(APizza::TaillePizza size);
  virtual ~Regina();

public:
  virtual const std::vector<APizza::Ingredients>& getIngredients() const;
};

#endif /* _REGINA_H_ */
