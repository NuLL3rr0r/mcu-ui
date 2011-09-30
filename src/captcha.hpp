#ifndef CAPTCHA_HPP
#define CAPTCHA_HPP


namespace Wt {
    class WImage;
}

namespace ControlConference {
    class Captcha;
}

class ControlConference::Captcha
{
public:
    std::size_t Result;

public:
    Captcha();

    Wt::WImage *GenCap();
};


#endif /* CAPTCHA_HPP */

