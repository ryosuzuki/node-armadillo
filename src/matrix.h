#ifndef MATRIX_H
#define MATRIX_H

#include <nan.h>
#include <node.h>
#include <armadillo>  // Armadillo: Linear Algebra package
#include <iostream>
#include <vector>
#include <algorithm>

using namespace v8;

template <typename T>
class matWrap : public node::ObjectWrap {

  public:
    static void Initialize(v8::Handle<v8::Object> target);
    arma::Mat<T>* GetWrapped() const { return q_; };
    void SetWrapped(arma::Mat<T> q) {
      if (q_) delete q_;
      q_ = new arma::Mat<T>(q);
      };

    static void registerMethods(Local<FunctionTemplate> tpl);
    static v8::Handle<v8::Value> NewInstance(arma::Mat<T> q);

    // check whether something is an instance of the matrix class
     static bool HasInstance(v8::Handle<v8::Value> value) {
 		 if (!value->IsObject()) return false;
 		 v8::Local<Object> obj = value->ToObject();
 		 return constructor->HasInstance(obj);
 		 }

    private:
    matWrap(const v8::Arguments& args);
    ~matWrap();

    static v8::Persistent<v8::FunctionTemplate> constructor;
    static NAN_METHOD(New);

  // Wrapped methods
   static NAN_METHOD(at);

   static NAN_METHOD(eye);

   static NAN_METHOD(fill);

   static NAN_METHOD(i);
   static NAN_METHOD(is_empty);
   static NAN_METHOD(is_finite);
   static NAN_METHOD(is_square);
   static NAN_METHOD(is_vec);
   static NAN_METHOD(is_colvec);
   static NAN_METHOD(is_rowvec);

   static NAN_METHOD(n_cols);
   static NAN_METHOD(n_rows);
   static NAN_METHOD(n_elem);

   static NAN_METHOD(ones);

   static NAN_METHOD(print);

   static NAN_METHOD(randu);
   static NAN_METHOD(randn);
   static NAN_METHOD(reset);
   static NAN_METHOD(resize);

   static NAN_METHOD(set_size);
   static NAN_METHOD(shed_row);
   static NAN_METHOD(shed_rows);
   static NAN_METHOD(shed_col);
   static NAN_METHOD(shed_cols);
   static NAN_METHOD(swap_rows);
   static NAN_METHOD(swap_cols);

   static NAN_METHOD(t);

   static NAN_METHOD(zeros);

   // Submatrix Views

   static NAN_METHOD(col);
   static NAN_METHOD(row);

   // Operators
   static NAN_METHOD(add);
   static NAN_METHOD(subtract);
   static NAN_METHOD(elementMultiply);
   static NAN_METHOD(elementDivide);

   // Accesors
   static NAN_PROPERTY_GETTER(GetNrow);
   static NAN_PROPERTY_GETTER(GetNcol);
   static NAN_PROPERTY_GETTER(GetNelem);

   // Wrapped object
   arma::Mat<T>* q_;
};

#include "matrix.cpp"

#endif
