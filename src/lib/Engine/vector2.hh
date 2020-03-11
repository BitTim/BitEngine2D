#pragma once

class Vector2
{
public:
  float x;
  float y;

  Vector2();
  Vector2(const float x, const float y);

  Vector2& set(const float x, const float y);
  Vector2& scale(const float scalar);

  Vector2& add(const Vector2& vec);
  Vector2& sub(const Vector2& vec);
  Vector2& mul(const Vector2& vec);
  Vector2& div(const Vector2& vec);

  friend Vector2& operator+(Vector2& v1, const Vector2& v2);
  friend Vector2& operator-(Vector2& v1, const Vector2& v2);
  friend Vector2& operator*(Vector2& v1, const Vector2& v2);
  friend Vector2& operator/(Vector2& v1, const Vector2& v2);

  Vector2& operator+=(const Vector2& vec);
  Vector2& operator+=(const Vector2& vec);
  Vector2& operator+=(const Vector2& vec);
  Vector2& operator+=(const Vector2& vec);

  Vector2& operator^(const float& s);
};