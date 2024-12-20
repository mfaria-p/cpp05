#ifndef EX03_FORM_HPP
# define EX03_FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;

    public:
        Form(); // default constructor
        Form(std::string name, int gradeToSign, int gradeToExecute); // grade 1-150
        Form(Form const &src); // copy constructor
        virtual ~Form(); // destructor
        Form &operator=(Form const &form); // assignment operator

        // getters
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // member functions
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        // Exception classes
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif