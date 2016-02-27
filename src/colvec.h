#ifndef COLVEC_H
#define COLVEC_H

#include <node.h>
#include <armadillo>  // Armadillo: Linear Algebra package
#include <iostream>
#include <vector>
#include <algorithm>

using namespace v8;

template <typename T>
class colvecWrap : public node::ObjectWrap {

public:
    static void Initialize(v8::Handle<v8::Object> target);
    arma::Col<T>* GetWrapped() const { return q_; };
    void SetWrapped(arma::Col<T> q) {
      if (q_) delete q_;
      q_ = new arma::Col<T>(q);
      };

    static void registerMethods(Local<FunctionTemplate> tpl);
    static v8::Handle<v8::Value> NewInstance(arma::Col<T> q);

    // check whether something is an instance of the colvec class
     static bool HasInstance(v8::Handle<v8::Value> value) {
 		 if (!value->IsObject()) return false;
 		 v8::Local<Object> obj = value->ToObject();
 		 return constructor->HasInstance(obj);
 		 }

  private:
     colvecWrap(const v8::Arguments& args);
    ~colvecWrap();
    static v8::Persistent<v8::FunctionTemplate> constructor;
    static NAN_METHOD(New);

    // Methods

    static NAN_METHOD(at);

    static NAN_METHOD(fill);

    static NAN_METHOD(is_empty);
    static NAN_METHOD(is_finite);

    static NAN_METHOD(print);

    static NAN_METHOD(randu);
    static NAN_METHOD(randn);
    static NAN_METHOD(reset);
    static NAN_METHOD(resize);


    static NAN_METHOD(set_size);
    static NAN_METHOD(shed_row);
    static NAN_METHOD(shed_rows);
    static NAN_METHOD(swap_rows);
    static NAN_METHOD(swap_cols);

    static NAN_METHOD(zeros);

    // Accesors
    static NAN_PROPERTY_GETTER(GetNrow);
    static NAN_PROPERTY_GETTER(GetNcol);
    static NAN_PROPERTY_GETTER(GetNelem);

	// Wrapped object
    arma::Col<T>* q_;
};

#include "colvec.cpp"

#endif
