#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QValidator>

class Validator :public QValidator
{
    Q_OBJECT
public:
    Validator(QObject *parent);
    ~Validator();

    QValidator::State validate(QString & string, int & pos) const;





};

#endif // VALIDATOR_H
