#ifndef _IPIZZA_H_
# define _IPIZZA_H_

# include <vector>

class APizza
{
public:
  enum Ingredients
    {
      Doe,
      Tomato,
      Gruyere,
      Ham,
      Mushrooms,
      Steak,
      Eggplant,
      GoatCheese,
      ChiefLove
    };

  enum TypePizza
    {
      Regina = 1,
      Margarita = 2,
      Americaine = 4,
      Fantasia = 8
    };

  enum TaillePizza
    {
      S = 1,
      M = 2,
      L = 4,
      XL = 8,
      XXL = 16
    };

protected:
  TypePizza _type;
  TaillePizza _size;
  bool _done;

public:
  explicit APizza(TypePizza type, TaillePizza size);
  virtual ~APizza() {}

public:
  virtual TaillePizza getSize() const;
  virtual TypePizza getType() const;
  virtual bool isDone() const;
  virtual void setDone(bool done);
  virtual const std::vector<Ingredients>& getIngredients() const = 0;
};

#endif /* _IPIZZA_H_ */
